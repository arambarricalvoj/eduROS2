#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
import socket
import threading
import math
from sensor_msgs.msg import JointState
from builtin_interfaces.msg import Time as TimeMsg

class UDPListener(Node):
    def __init__(self):
        super().__init__('udp_listener')

        self.joint_pub = self.create_publisher(JointState, 'joint_states', 10)

        # Crear socket UDP
        self.udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.udp_socket.bind(("0.0.0.0", 5000))  # Escuchar en todas las interfaces, puerto 54321
        self.get_logger().info("Esperando datos UDP en el puerto 5000...")

        # Iniciar un hilo para recibir los paquetes UDP
        self.udp_thread = threading.Thread(target=self.receive_data)
        self.udp_thread.daemon = True  # El hilo se cerrará cuando el programa termine
        self.udp_thread.start()


    def degrees_to_radians_wrapped(self, degrees):
        r = math.radians(degrees)
        return math.remainder(r, 2 * math.pi)  # Devuelve en [-pi, pi]

    
    def receive_data(self):
        while rclpy.ok():  # Asegura que el hilo se ejecute mientras ROS2 esté activo
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
                self.get_logger().error(f"Error al recibir datos: {e}")

def main(args=None):
    rclpy.init(args=args)
    node = UDPListener()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == "__main__":
    main()
