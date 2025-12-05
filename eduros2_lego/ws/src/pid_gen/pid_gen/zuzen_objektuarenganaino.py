# --- INPORTAZIOAK ---
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from std_msgs.msg import Int32
from sensor_msgs.msg import Range
from rclpy.callback_groups import ReentrantCallbackGroup
import random
import math
import time

# KP 4.68 MEJOR QUE KP 7

class ZuzenObjektuarenganaino(Node):
    def __init__(self):
        super().__init__('zuzen_objektuarenganaino')
        self.get_logger().info("Nodo PID+GA iniciado\n")

        self.nodoa_itxi = False
        self.callback_group = ReentrantCallbackGroup()

        # Parámetros de movimiento
        self.declare_parameter('abiadura', 0.2)
        self.declare_parameter('eten_distantzia', 0.15)
        self.abiadura = self.get_parameter('abiadura').value
        self.eten_distantzia = self.get_parameter('eten_distantzia').value

        # Estado sensores
        self.yaw_angelua = None
        self.offset = None
        self.ultrasoinu_distantzia = None

        # PID variables
        self.kp = 1.0
        self.ki = 0.0   # simplificación: Ki = 0
        self.kd = 0.0   # simplificación: Kd = 0
        self.integral = 0.0
        self.last_error = 0.0

        # Publicador y subscripciones
        self.cmd_vel_pub = self.create_publisher(Twist, 'cmd_vel', 10)
        self.biraketa_sentsorea_entzulea = self.create_subscription(
            Int32, 'yaw_angelua', self.biraketa_sentsorea_callback, 10,
            callback_group=self.callback_group)
        self.ultrasoinu_sentsorea_entzulea = self.create_subscription(
            Range, 'distantzia', self.ultrasoinu_sentsorea_callback, 10,
            callback_group=self.callback_group)

        # Timer principal
        self.timer = self.create_timer(0.1, self.mugitu_objektuarenganaino,
                                       callback_group=self.callback_group)

        # --- GA setup (solo Kp) ---
        self.pop_size = 6
        self.generations = 5
        self.episode_duration = 4.0  # segundos por evaluación
        self.population = [self.crear_individuo() for _ in range(self.pop_size)]
        self.gen_index = 0
        self.ind_index = 0
        self.running_episode = False
        self.episode_start = None
        self.ep_errors = []
        self.ep_outputs = []
        self.best_kp = self.kp
        self.best_fitness = 1e9

    # ---------------- SENSORES ----------------
    def biraketa_sentsorea_callback(self, mezua: Int32):
        self.yaw_angelua = mezua.data
        if self.offset is None:
            self.offset = self.yaw_angelua
            self.get_logger().info(f"Offset: {self.offset}")

    def ultrasoinu_sentsorea_callback(self, mezua: Range):
        self.ultrasoinu_distantzia = mezua.range

    # ---------------- PID SIMPLE ----------------
    def pid_step(self):
        error = (self.yaw_angelua - self.offset)
        error_percent = error * 100 / 360
        self.integral = self.integral + error_percent
        derivada = error_percent - self.last_error
        salida_pid = (error_percent * self.kp) + (self.integral * self.ki) + (derivada * self.kd)
        self.last_error = error_percent
        return salida_pid

    # ---------------- CONTROL LOOP ----------------
    def mugitu_objektuarenganaino(self):
        if self.yaw_angelua is None or self.offset is None or self.ultrasoinu_distantzia is None:
            return

        if self.ultrasoinu_distantzia <= self.eten_distantzia:
            self.stop_and_cancel("Objektua hurbil dago. Nodoa gelditzen...")
            return

        # PID con el mejor Kp actual (Ki y Kd = 0)
        correc_pid = self.pid_step()
        cmd = Twist()
        cmd.linear.x = self.abiadura
        cmd.angular.z = self.abiadura * (correc_pid * 0.01)
        self.cmd_vel_pub.publish(cmd)

        # GA paso
        self.ga_step()

    # ---------------- GA ----------------
    def crear_individuo(self):
        return random.uniform(4.0, 9.0)  # solo Kp

    def fitness_function(self, errors, outputs):
        if not errors:
            return 1e9

        N = len(errors)

        # --- 1. Oscilaciones ---
        # Variación media entre salidas consecutivas
        osc_sum = sum(abs(outputs[i] - outputs[i-1]) for i in range(1, N))
        osc_avg = osc_sum / max(1, (N-1))

        # --- 2. Tiempo de recuperación ---
        # Número de muestras fuera del rango ±5%
        recovery_time = sum(1 for e in errors if abs(e) > 2)

        # --- Fitness total ---
        # Pesos ajustables: w_osc y w_rec
        w_osc = 0.2   # penalización de oscilaciones
        w_rec = 0.5   # penalización de tiempo fuera de rango

        fitness = w_osc * osc_avg + w_rec * recovery_time
        return fitness



    def ga_step(self):
        if self.gen_index >= self.generations:
            return

        if not self.running_episode:
            if self.ind_index >= self.pop_size:
                # Nueva generación
                self.population = [self.crear_individuo() for _ in range(self.pop_size)]
                self.ind_index = 0
                self.gen_index += 1
                self.get_logger().info(f"Generación {self.gen_index} lista")

            # Preparar episodio
            self.integral = 0.0
            self.last_error = 0.0
            self.ep_errors = []
            self.ep_outputs = []
            self.episode_start = time.time()
            self.running_episode = True
            # Cargar individuo actual
            self.kp = self.population[self.ind_index]
            self.ki = 0.0
            self.kd = 0.0
            self.get_logger().info(f"Probando Kp = {self.kp:.2f} durante {self.episode_duration} segundos")

        # Durante episodio
        error = (self.yaw_angelua - self.offset)
        error_percent = error * 100 / 360
        correc_pid = (error_percent * self.kp)
        self.ep_errors.append(error_percent)
        self.ep_outputs.append(correc_pid)

        if (time.time() - self.episode_start) >= self.episode_duration:
            fit = self.fitness_function(self.ep_errors, self.ep_outputs)
            self.get_logger().info(f"Kp probado: {self.kp:.2f}, fitness={fit:.3f}")
            if fit < self.best_fitness:
                self.best_fitness = fit
                self.best_kp = self.kp
                self.get_logger().info(f"Nuevo mejor Kp: {self.kp:.2f}, fit={fit:.3f}")
            self.ind_index += 1
            self.running_episode = False

    def stop_and_cancel(self, msg):
        cmd = Twist()
        self.cmd_vel_pub.publish(cmd)
        self.get_logger().info(msg)
        self.nodoa_itxi = True
        self.timer.cancel()


def main(args=None):
    rclpy.init(args=args)
    nodo = ZuzenObjektuarenganaino()
    try:
        while rclpy.ok():
            rclpy.spin_once(nodo, timeout_sec=0.1)
            if nodo.nodoa_itxi:
                break
    except KeyboardInterrupt:
        nodo.get_logger().info("Erabiltzaileak nodoa gelditu du.")
    finally:
        nodo.destroy_node()
        nodo.get_logger().info("Nodoa amaitu da.")
        rclpy.shutdown()


if __name__ == '__main__':
    main()
