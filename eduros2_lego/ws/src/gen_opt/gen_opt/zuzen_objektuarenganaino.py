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
import csv

class ZuzenObjektuarenganaino(Node):
    def __init__(self):
        super().__init__('zuzen_objektuarenganaino')
        self.get_logger().info("PID optimizazio gnetikoaren nodoa hasita\n")

        self.nodoa_itxi = False
        self.callback_group = ReentrantCallbackGroup()

        # Mugimendu aldagaiak
        self.declare_parameter('abiadura', 25.0)
        self.declare_parameter('eten_distantzia', 0.15)
        self.abiadura = self.get_parameter('abiadura').value
        self.eten_distantzia = self.get_parameter('eten_distantzia').value

        # Sentsore aldagaiak hasiarazi
        self.yaw_angelua = None
        self.offset = None
        self.ultrasoinu_distantzia = None

        # PID aldagaiak
        self.kp = 1.0
        self.ki = 0.0   # simplificación: Ki = 0
        self.kd = 0.0   # simplificación: Kd = 0
        self.integral = 0.0
        self.last_error = 0.0

        # Argitaratzaileak eta harpidetzak
        self.cmd_vel_pub = self.create_publisher(Twist, 'cmd_vel', 10)
        self.biraketa_sentsorea_entzulea = self.create_subscription(
            Int32, 'yaw_angelua', self.biraketa_sentsorea_callback, 10,
            callback_group=self.callback_group)
        self.ultrasoinu_sentsorea_entzulea = self.create_subscription(
            Range, 'distantzia', self.ultrasoinu_sentsorea_callback, 10,
            callback_group=self.callback_group)

        # Timer-a: 0.1 segunduro funtzioa exekutatzen da
        self.timer = self.create_timer(0.1, self.mugitu_objektuarenganaino,
                                       callback_group=self.callback_group)

        # GA aldagaiak (bakarrik Kp)
        self.biztanleria_tamaina = 6
        self.belaunaldiak = 5
        self.gertakati_iraupena = 4.0  # segundu episodio bakoitzeko
        self.biztanleria = [self.indibiduoa_sortu() for _ in range(self.biztanleria_tamaina)]
        self.gen_index = 0
        self.ind_index = 0
        self.gertakari_exekutatzen = False
        self.gertakari_hasiera = None
        self.ep_errors = []
        self.ep_outputs = []
        self.kp_onena = self.kp
        self.fitness_onena = 1e9
        self.fitnesses = []
        self.w_osc = 0.2
        self.w_tr = 0.5

        # Eboluzioa gordetzeko .csv
        self.csv_file = "evolucion_ga.csv"
        with open(self.csv_file, mode="w", newline="") as f:
            writer = csv.writer(f)
            writer.writerow(["Generacion", "Individuo", "Kp", "Fitness"])

        # Guardar población inicial en CSV
        """with open(self.csv_file, mode="a", newline="") as f:
            writer = csv.writer(f)
            for i, kp in enumerate(self.biztanleria):
                writer.writerow([0, i, kp, "NA"])  # fitness aún no calculado"""


    def biraketa_sentsorea_callback(self, mezua: Int32):
        self.yaw_angelua = mezua.data
        if self.offset is None:
            self.offset = self.yaw_angelua
            self.get_logger().info(f"Offset: {self.offset}")


    def ultrasoinu_sentsorea_callback(self, mezua: Range):
        self.ultrasoinu_distantzia = mezua.range


    def pid_urratsa(self):
        error = (self.yaw_angelua - self.offset)
        error_percent = error * 100 / 360
        self.integral = self.integral + error_percent
        derivada = error_percent - self.last_error
        salida_pid = (error_percent * self.kp) + (self.integral * self.ki) + (derivada * self.kd)
        self.last_error = error_percent
        return salida_pid


    def mugitu_objektuarenganaino(self):
        if self.yaw_angelua is None or self.offset is None or self.ultrasoinu_distantzia is None:
            return

        if self.ultrasoinu_distantzia <= self.eten_distantzia:
            self.gelditu("Objektua hurbil dago. Nodoa gelditzen...")
            return

        pid_zuzenketa = self.pid_urratsa()
        cmd = Twist()
        cmd.linear.x = self.abiadura
        cmd.angular.z = self.abiadura * (pid_zuzenketa * 0.01)
        self.cmd_vel_pub.publish(cmd)

        self.ga_urratsa()


    def indibiduoa_sortu(self):
        # Ausazko hasieraketa lehen belaunaldirako bakarrik
        return random.uniform(4.0, 9.0)

    def gurutzaldia(self, parent1, parent2):
        # Bidegurutze sinplea: batez bestekoa + aldaketa txikia
        beta = random.random()  # nahasketa-faktorea
        ume = beta * parent1 + (1 - beta) * parent2
        return ume

    def mutatu(self, indibiduoa, mutazio_tasa=0.1):
        # Mutazioa: zarata gaussiarra gehitu
        if random.random() < mutazio_tasa:
            indibiduoa += random.uniform(-0.5, 0.5)

        # Baimendutako tartean mantendu
        return max(4.0, min(9.0, indibiduoa))

    def belaunaldi_berria(self, fitnesses):
        # Hautaketa: fitness arabera ordenatu (txikiagoa hobea da)
        sorted_pop = [x for _, x in sorted(zip(fitnesses, self.biztanleria))]

        # Elitismoa: 2 onenak mantendu
        new_pop = sorted_pop[:2]

        # Seme-alabak sortzea, gurutzaketaren eta mutazioaren bidez
        while len(new_pop) < self.biztanleria_tamaina:
            if len(sorted_pop) >= 2:
                p1, p2 = random.sample(sorted_pop, 2)
            else:
                p1 = p2 = sorted_pop[0]
            ume = self.gurutzaldia(p1, p2)
            ume = self.mutatu(ume)
            new_pop.append(ume)

        return new_pop


    def fitness_funtzioa(self, errors, outputs):
        if not errors:
            return 1e9

        N = len(errors)

        # 1. Oszilazioak
        osc_sum = sum(abs(outputs[i] - outputs[i-1]) for i in range(1, N))
        osc_avg = osc_sum / max(1, (N-1))

        # 2. Berreskuratze-denbora (±% 2tik kanpoko laginak)
        recovery_time = sum(1 for e in errors if abs(e) > 2)

        # Fitness totala
        fitness = self.w_osc * osc_avg + self.w_tr * recovery_time
        return fitness


    def ga_urratsa(self):
        if self.gen_index >= self.belaunaldiak:
            return

        if not self.gertakari_exekutatzen:
            if self.ind_index >= self.biztanleria_tamaina:
                # Belaunaldi berria fitness metatuekin
                self.biztanleria = self.belaunaldi_berria(self.fitnesses)
                self.fitnesses = []
                self.ind_index = 0
                self.gen_index += 1
                self.get_logger().info(f"Generación {self.gen_index} lista")

            # Gertakaria prestatu
            self.integral = 0.0
            self.last_error = 0.0
            self.ep_errors = []
            self.ep_outputs = []
            self.gertakari_hasiera = time.time()
            self.gertakari_exekutatzen = True
            self.kp = self.biztanleria[self.ind_index]
            self.get_logger().info(f"Probatzen Kp = {self.kp:.2f}, {self.gertakati_iraupena} segundoz")

        # Gertakarian zehar
        error = (self.yaw_angelua - self.offset)
        error_percent = error * 100 / 360
        pid_zuzenketa = (error_percent * self.kp)
        self.ep_errors.append(error_percent)
        self.ep_outputs.append(pid_zuzenketa)

        if (time.time() - self.gertakari_hasiera) >= self.gertakati_iraupena:
            fit = self.fitness_funtzioa(self.ep_errors, self.ep_outputs)
            self.fitnesses.append(fit)  # fitness gorde
            self.get_logger().info(f"Kp probatuta: {self.kp:.2f}, fitness={fit:.3f}")
            
            # CSV-n datuak gorde
            with open(self.csv_file, mode="a", newline="") as f:
                writer = csv.writer(f)
                writer.writerow([self.gen_index, self.ind_index, self.kp, fit])


            if fit < self.fitness_onena:
                self.fitness_onena = fit
                self.kp_onena = self.kp
                self.get_logger().info(f"Kp berri hobea: {self.kp:.2f}, fitness={fit:.3f}")
            self.ind_index += 1
            self.gertakari_exekutatzen = False


    def gelditu(self, msg):
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
