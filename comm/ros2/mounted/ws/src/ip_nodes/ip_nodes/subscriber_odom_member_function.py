#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
import socket
import threading

class UDPListener(Node):
    def __init__(self):
        super().__init__('udp_listener')

        # Crear socket UDP
        self.udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.udp_socket.bind(("0.0.0.0", 54321))  # Escuchar en todas las interfaces, puerto 54321
        self.get_logger().info("Esperando datos UDP en el puerto 54321...")

        # Iniciar un hilo para recibir los paquetes UDP
        self.udp_thread = threading.Thread(target=self.receive_data)
        self.udp_thread.daemon = True  # El hilo se cerrará cuando el programa termine
        self.udp_thread.start()

    def receive_data(self):
        while rclpy.ok():  # Asegura que el hilo se ejecute mientras ROS2 esté activo
            try:
                data, addr = self.udp_socket.recvfrom(1024)  # Recibe hasta 1024 bytes
                mensaje = data.decode(errors='ignore')
                self.get_logger().info(f"Recibido desde {addr}: {mensaje}")
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
