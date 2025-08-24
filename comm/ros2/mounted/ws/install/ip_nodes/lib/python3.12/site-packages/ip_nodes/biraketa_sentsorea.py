import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
from std_msgs.msg import Int32

import random
import socket
import threading
import math

class BiraketaSentsorea(Node):
    def __init__(self):
        super().__init__('biraketa_sentsorea')
        self.get_logger().info("nodoa hasiarazi da\n")

        # Argitaratzaileak
        self.joint_pub = self.create_publisher(JointState, 'joint_states', 10)
        self.publisher_ = self.create_publisher(Int32, 'yaw_angelua', 10)

        # UDP klase aldagaiak kodetzaileen informazioa jasotzeko
        self.udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        try:
            self.udp_socket.bind(("0.0.0.0", 5002))  # Escuchar en todas las interfaces, puerto 5002
            self.get_logger().info("5002 UDP portuan ultrasoinu sentsoaren datuen zain.")
        except Exception as e:
            self.get_logger().error(f"Ezin izan da UDP ataka ireki: {e}")

        # UDP haria hasi (threads)
        threading.Thread(target=self.receive_data_udp, daemon=True).start()


    def receive_data_udp(self):
        self.get_logger().info("Biraketa sentsorea /yaw_angelua topikoan argitaratzen.")
        while rclpy.ok():
            try:
                data, addr = self.udp_socket.recvfrom(1024)  # Recibe hasta 1024 bytes
                mezua = data.decode(errors='ignore')

                try:
                    angelua = int(mezua)
                except ValueError:
                    self.get_logger().warn("No se pudo convertir el valor a float")
                    continue

                # Publicar en joint_states
                js = JointState()
                js.header.stamp = self.get_clock().now().to_msg()
                js.name = ['base_gyro_joint']
                js.position = [float((-1) * math.radians(angelua))]
                self.joint_pub.publish(js)

                msg = Int32()
                msg.data = angelua
                self.publisher_.publish(msg)

            except Exception as e:
                self.get_logger().error(f"Error al recibir datos UDP: {e}")

def main(args=None):
    rclpy.init(args=args)
    node = BiraketaSentsorea()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
