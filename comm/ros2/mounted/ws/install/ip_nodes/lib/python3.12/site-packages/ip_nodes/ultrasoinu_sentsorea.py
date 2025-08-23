import rclpy
from rclpy.node import Node
import random
from sensor_msgs.msg import Range

import socket
import threading
import math

class UltrasoinuSentsorea(Node):
    def __init__(self):
        super().__init__('ultrasoinu_sentsorea')
        self.get_logger().info("nodoa hasiarazi da\n")

        # Argitaratzaileak
        self.publisher_ = self.create_publisher(Range, 'distantzia', 10)

        # UDP klase aldagaiak kodetzaileen informazioa jasotzeko
        self.udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        try:
            self.udp_socket.bind(("0.0.0.0", 5001))  # Escuchar en todas las interfaces, puerto 5001
            self.get_logger().info("5001 UDP portuan ultrasoinu sentsoaren datuen zain.")
        except Exception as e:
            self.get_logger().error(f"Ezin izan da UDP ataka ireki: {e}")

        # UDP haria hasi (threads)
        threading.Thread(target=self.receive_data_udp, daemon=True).start()


    def receive_data_udp(self):
        self.get_logger().info("Ultrasoinu sentsorea /distantzia topikoan argitaratzen.")
        while rclpy.ok():
            try:
                data, addr = self.udp_socket.recvfrom(1024)  # Recibe hasta 1024 bytes
                mezua = data.decode(errors='ignore')

                try:
                    distantzia = float(mezua)/100.0
                except ValueError:
                    self.get_logger().warn("No se pudo convertir el valor a float")
                    continue

                # Mensaje base
                msg = Range()
                msg.header.stamp = self.get_clock().now().to_msg()
                msg.header.frame_id = 'ultrasonic'  # Debe coincidir con el link del URDF
                msg.radiation_type = Range.ULTRASOUND
                msg.field_of_view = math.radians(30)  # 30 grados -> 0.523598... rad
                msg.min_range = 0.01      # 1 cm
                msg.max_range = 2.50      # 250 cm
                msg.range = distantzia

                self.publisher_.publish(msg)

            except Exception as e:
                self.get_logger().error(f"Error al recibir datos UDP: {e}")

def main(args=None):
    rclpy.init(args=args)
    node = UltrasoinuSentsorea()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
