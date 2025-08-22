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


class MugimenduMotorrak(Node):
    def __init__(self):
        super().__init__('mugimendu_motorrak')  # ROS2-n izango duen izena
        self.get_logger().info("nodoa hasiarazi da\n")

        # Argitaratzaileak
        self.joint_pub = self.create_publisher(JointState, 'joint_states', 10)
        
        # Entzuleak
        self.mugimendua_entzulea = self.create_subscription(
            Twist,
            'cmd_vel',
            self.mugimendua_entzulea_callback,
            10
        )

        # TCP klase aldagaiak motorrak kontrolatzeko
        self.bezero_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        try:
            self.bezero_socket.connect(("192.168.1.140", 12345))
            self.bezero_socket.setblocking(False)  # Mandar paquete sin esperar respuesta
            self.get_logger().info("TCP konexioa ezarrita 192.168.1.140:12345 helbidearekin, /cmd_vel topikoaren informazioa bidaltzen.\n")
        except Exception as e:
            self.get_logger().error(f"Ezin izan da TCP bidez konektatu: {e}")

        # UDP klase aldagaiak kodetzaileen informazioa jasotzeko
        self.udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        try:
            self.udp_socket.bind(("0.0.0.0", 5000))  # Escuchar en todas las interfaces, puerto 5000
            self.get_logger().info("5000 UDP portuan mugimendu motorren kodetzaileen datuen zain.")
        except Exception as e:
            self.get_logger().error(f"Ezin izan da UDP ataka ireki: {e}")

        # UDP haria hasi (threads)
        threading.Thread(target=self.receive_data_udp, daemon=True).start()


    def mugimendua_entzulea_callback(self, mezua):
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
            self.get_logger().error(f"Errorea TCP bidaltzean: {e}")

    def graduak_radianetara(self, degrees):
        """Convierte grados a radianes, normalizados en el rango [-pi, pi]."""
        rad = math.radians(degrees)
        return math.remainder(rad, 2 * math.pi)

    def receive_data_udp(self):
        self.get_logger().info("Mugimendu kodetzaileak /joint_states topikoan argitaratzen.")
        while rclpy.ok():
            try:
                data, addr = self.udp_socket.recvfrom(1024)  # Recibe hasta 1024 bytes
                mezua = data.decode(errors='ignore')
                #self.get_logger().info(f"Recibido desde {addr}: {mezua}")

                # Procesar el mensaje
                partes = mezua.split(',')
                if len(partes) != 2:
                    self.get_logger().warn("Formato inválido, se esperaban dos valores separados por coma")
                    continue

                try:
                    left_deg = float(partes[0])
                    right_deg = float(partes[1])
                except ValueError:
                    self.get_logger().warn("No se pudieron convertir los valores a float")
                    continue

                left_rad = self.graduak_radianetara(left_deg)
                right_rad = self.graduak_radianetara(right_deg)

                # Publicar en joint_states
                js = JointState()
                now = self.get_clock().now().to_msg()
                js.header.stamp = now
                js.name = ['base_left_wheel_joint', 'base_right_wheel_joint']
                js.position = [left_rad, right_rad]

                self.joint_pub.publish(js)

            except Exception as e:
                self.get_logger().error(f"Error al recibir datos UDP: {e}")


def main(args=None):
    rclpy.init(args=args)
    mugimendu_motorrak = MugimenduMotorrak()
    rclpy.spin(mugimendu_motorrak) 
    mugimendu_motorrak.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
