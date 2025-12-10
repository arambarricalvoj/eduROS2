import rclpy
from rclpy.node import Node
from visualization_msgs.msg import Marker, MarkerArray
from std_msgs.msg import ColorRGBA
from mezuak.msg import IslatutakoArgia
from transformations import quaternion_from_euler

import socket
import threading
import math

class KoloreSentsorea(Node):
    def __init__(self):
        super().__init__('kolore_sentsorea')
        self.get_logger().info("nodoa hasiarazi da\n")

        self.ezker_islatutako_argia = None
        self.eskuin_islatutako_argia = None

        # Argitaratzaileak
        self.argia_pub = self.create_publisher(IslatutakoArgia, 'islatutako_argia', 10)
        self.rviz_left_marker_pub = self.create_publisher(Marker, 'left_light_sensor_marker', 10)
        self.rviz_right_marker_pub = self.create_publisher(Marker, 'right_light_sensor_marker', 10)

        self.intensity = 0.5   # valor entre 0 y 1
        self.mode_rgb = False
        self.rgb = (0.2, 0.8, 0.1)  # ejemplo: verde

        # UDP klase aldagaiak kodetzaileen informazioa jasotzeko
        self.udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        try:
            self.udp_socket.bind(("0.0.0.0", 5003))  # Escuchar en todas las interfaces, puerto 5001
            self.get_logger().info("5003 UDP portuan kolore sentsoreen datuen zain.")
        except Exception as e:
            self.get_logger().error(f"Ezin izan da UDP ataka ireki: {e}")

        # UDP haria hasi (threads)
        threading.Thread(target=self.receive_data_udp, daemon=True).start()


    def receive_data_udp(self):
        self.get_logger().info("Kolore sentsorea /islatutako_argia topikoan argitaratzen.")
        while rclpy.ok():
            try:
                data, addr = self.udp_socket.recvfrom(1024)
                mezua = data.decode(errors='ignore')

                # Mezua prozesatu
                partes = mezua.split(',')
                if len(partes) != 2:
                    self.get_logger().warn("Formato inválido, se esperaban dos valores separados por coma")
                    continue

                try:
                    self.ezker_islatutako_argia = int(partes[0])
                    self.eskuin_islatutako_argia = int(partes[1])
                except ValueError:
                    self.get_logger().warn("No se pudieron convertir los valores a int")
                    continue

                # Mezua argitaratu
                ia = IslatutakoArgia()
                ia.argi_intentsitateak[0] = self.ezker_islatutako_argia
                ia.argi_intentsitateak[1] = self.eskuin_islatutako_argia
                self.argia_pub.publish(ia)

                self.marker_eguneratu()


            except Exception as e:
                self.get_logger().error(f"Error al recibir datos UDP: {e}")

    def marker_eguneratu(self):
        #array_marker = MarkerArray()
        q = quaternion_from_euler(math.pi, 0, 0)  # rotación 180° en X para que el marker apunte al suelo
        # ya que el eje Z positivo del sensor va hacia arriba.

        ezker_marker = Marker()
        ezker_marker.ns = "kolore_sentsoreak"
        ezker_marker.id = 0
        ezker_marker.header.frame_id = "left_color_light_sensor"   # el link de tu URDF
        ezker_marker.header.stamp = self.get_clock().now().to_msg()
        ezker_marker.type = Marker.CYLINDER
        ezker_marker.action = Marker.ADD
        ezker_marker.scale.x = 0.05  # diámetro
        ezker_marker.scale.y = 0.05
        ezker_marker.scale.z = 0.11   # longitud del haz
        ezker_marker.pose.orientation.x = q[0]
        ezker_marker.pose.orientation.y = q[1]
        ezker_marker.pose.orientation.z = q[2]
        ezker_marker.pose.orientation.w = q[3]
        ezker_marker.pose.position.z = -ezker_marker.scale.z / 2.0 #ezker_marker.pose.position.z = 0.1

        alpha = self.ezker_islatutako_argia / 100
        ezker_marker.color = ColorRGBA(r=1.0, g=0.0, b=0.0, a=alpha)

        """if self.mode_rgb:
            r, g, b = self.rgb
            marker.color = ColorRGBA(r=r, g=g, b=b, a=0.8)
        else:
            marker.color = ColorRGBA(r=1.0, g=0.0, b=0.0, a=self.intensity)"""

        #array_marker.markers.append(ezker_marker)
        self.rviz_left_marker_pub.publish(ezker_marker)


        eskuin_marker = Marker()
        eskuin_marker.ns = "kolore_sentsoreak"
        eskuin_marker.id = 1
        eskuin_marker.header.frame_id = "right_color_light_sensor"   # el link de tu URDF
        eskuin_marker.header.stamp = self.get_clock().now().to_msg()
        eskuin_marker.type = Marker.CYLINDER
        eskuin_marker.action = Marker.ADD
        eskuin_marker.scale.x = 0.05  # diámetro en X
        eskuin_marker.scale.y = 0.05 # diámetro en Y
        eskuin_marker.scale.z = 0.11   # longitud del haz
        eskuin_marker.pose.orientation.x = q[0]
        eskuin_marker.pose.orientation.y = q[1]
        eskuin_marker.pose.orientation.z = q[2]
        eskuin_marker.pose.orientation.w = q[3]
        eskuin_marker.pose.position.z = -eskuin_marker.scale.z / 2.0

        alpha = self.eskuin_islatutako_argia / 100
        eskuin_marker.color = ColorRGBA(r=1.0, g=0.0, b=0.0, a=alpha)

        """
        scale.z = altura del cilindro (a lo largo del eje Z local del frame).
        El cilindro se dibuja centrado en su origen. Es decir, si scale.z = 0.2, 
        el cilindro mide 20 cm de alto y se extiende 0.1 m hacia arriba y 0.1 m hacia abajo desde pose.position."""


        """if self.mode_rgb:
            r, g, b = self.rgb
            marker.color = ColorRGBA(r=r, g=g, b=b, a=0.8)
        else:
            marker.color = ColorRGBA(r=1.0, g=0.0, b=0.0, a=self.intensity)"""

        #array_marker.markers.append(eskuin_marker)
        self.rviz_right_marker_pub.publish(eskuin_marker)



def main(args=None):
    rclpy.init(args=args)
    node = KoloreSentsorea()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
