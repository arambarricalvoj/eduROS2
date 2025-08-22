#!/usr/bin/env python3

# --- INPORTAZIOAK ---
# ROS2 liburutegiak
import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from geometry_msgs.msg import Twist
from sensor_msgs.msg import JointState
from builtin_interfaces.msg import Time as TimeMsg

# Beste liburutegiak
import socket
import threading
import math
# --- INPORTAZIOAK ---


class MotorrakTCPUDP(Node):
    def __init__(self):
        super().__init__('motorrak_tcp_udp')  # ROS2-n izango duen izena
        self.get_logger().info("Nodo combinado (TCP + UDP) iniciado\n")

        # === Suscripción para recibir comandos de movimiento (Twist) ===
        self.mugimendua_entzulea = self.create_subscription(
            Twist,
            'cmd_vel',
            self.mugimendua_entzulea_callback,
            10
        )

        # --- TCP: Conexión para envío de comandos de movimiento ---
        self.bezero_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        try:
            self.bezero_socket.connect(("192.168.1.140", 12345))
            self.bezero_socket.setblocking(False)  # Mandar paquete sin esperar respuesta
            self.get_logger().info("Conexión TCP establecida con 192.168.1.140:12345")
        except Exception as e:
            self.get_logger().error(f"No se pudo conectar vía TCP: {e}")

        # --- UDP: Configuración para recibir datos de encoders ---
        self.udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        try:
            self.udp_socket.bind(("0.0.0.0", 5000))  # Escuchar en todas las interfaces, puerto 5000
            self.get_logger().info("Esperando datos UDP en el puerto 5000...")
        except Exception as e:
            self.get_logger().error(f"No se pudo abrir el puerto UDP: {e}")

        # Publicador para /joint_states
        self.joint_pub = self.create_publisher(JointState, 'joint_states', 10)

        # === Arranque de hilos ===
        # Hilo independiente para recepción de UDP (no bloquea la suscripción de cmd_vel)
        threading.Thread(target=self.receive_data_udp, daemon=True).start()
        # Si quisieras un hilo específico para envío TCP continuo, se arrancaría aquí.
        # En este caso el envío se hace solo en el callback de cmd_vel.

    # --- Callback de ROS2: movimiento recibido por tópico ---
    def mugimendua_entzulea_callback(self, mezua):
        """
        Procesa el mensaje Twist y lo envía por TCP al motor.
        Mantiene la lógica original con distinción por tipo de movimiento.
        """
        try:
            if mezua.linear.x < 0.0 and mezua.angular.z == 0.0:  # Aurrera
                self.bezero_socket.send(f'tank_drive.on(SpeedPercent({int(mezua.linear.x)}*(1)),SpeedPercent({int(mezua.linear.x)}*(1)))\n'.encode())
            elif mezua.linear.x > 0.0 and mezua.angular.z == 0.0:  # Atzera
                self.bezero_socket.send(f'tank_drive.on(SpeedPercent({int(mezua.linear.x)}*(1)),SpeedPercent({int(mezua.linear.x)}*(1)))\n'.encode())
            elif mezua.linear.x == 0.0 and mezua.angular.z > 0.0:  # Ezkerra
                self.bezero_socket.send(f'tank_drive.on(SpeedPercent({int(mezua.angular.z)}*(1)),SpeedPercent({int(mezua.angular.z)}*(-1)))\n'.encode())
            elif mezua.linear.x == 0.0 and mezua.angular.z < 0.0:  # Eskuina
                self.bezero_socket.send(f'tank_drive.on(SpeedPercent({int(mezua.angular.z)}*(1)),SpeedPercent({int(mezua.angular.z)}*(-1)))\n'.encode())
            elif mezua.linear.x == 0.0 and mezua.angular.z == 0.0:  # Gelditu
                self.bezero_socket.send('tank_drive.off()\n'.encode())
        except Exception as e:
            self.get_logger().error(f"Error en envío TCP: {e}")

    # --- Funciones auxiliares para UDP ---
    def degrees_to_radians_wrapped(self, degrees):
        """Convierte grados a radianes, normalizados en el rango [-pi, pi]."""
        r = math.radians(degrees)
        return math.remainder(r, 2 * math.pi)

    def receive_data_udp(self):
        """
        Hilo dedicado a escuchar datos de encoders por UDP.
        Publica en /joint_states tan pronto como recibe un paquete válido.
        Este hilo es completamente independiente del envío TCP.
        """
        while rclpy.ok():
            try:
                data, addr = self.udp_socket.recvfrom(1024)  # Recibe hasta 1024 bytes
                mensaje = data.decode(errors='ignore')
                self.get_logger().info(f"Recibido desde {addr}: {mensaje}")

                # Procesar el mensaje
                partes = mensaje.split(',')
                if len(partes) != 2:
                    self.get_logger().warn("Formato inválido, se esperaban dos valores separados por coma")
                    continue

                try:
                    left_deg = float(partes[0])
                    right_deg = float(partes[1])
                except ValueError:
                    self.get_logger().warn("No se pudieron convertir los valores a float")
                    continue

                left_rad = self.degrees_to_radians_wrapped(left_deg)
                right_rad = self.degrees_to_radians_wrapped(right_deg)

                # Publicar en joint_states
                js = JointState()
                now = self.get_clock().now().to_msg()
                js.header.stamp = now
                js.name = ['base_left_wheel_joint', 'base_right_wheel_joint']
                js.position = [left_rad, right_rad]

                self.joint_pub.publish(js)
                self.get_logger().info("Publicado en /joint_states!")

            except Exception as e:
                self.get_logger().error(f"Error al recibir datos UDP: {e}")


def main(args=None):
    rclpy.init(args=args)
    nodo = MotorrakTCPUDP()
    try:
        rclpy.spin(nodo)  # Mantiene callbacks de ROS y deja que los hilos funcionen
    except KeyboardInterrupt:
        pass
    finally:
        nodo.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
