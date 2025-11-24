# --- INPORTAZIOAK ---
# ROS2 liburutegiak
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from mezuak.msg import MugimenduKodetzaileak
from std_srvs.srv import Trigger

# Beste liburutegiak
import socket
import threading
import math
# --- INPORTAZIOAK ---


class MugimenduMotorrak(Node):
    def __init__(self):
        super().__init__('mugimendu_motorrak')  # ROS2-n izango duen izena
        self.get_logger().info("nodoa hasiarazi da\n")

        # Parametroak
        self.declare_parameter('abiadura', 25.0)
        self.declare_parameter('motor_alderantzikatuak', False)

        self.abiadura = self.get_parameter('abiadura').value        
        self.motor_alderantzikatuak = self.get_parameter('motor_alderantzikatuak').value

        # Argitaratzaileak
        self.kodetzaileak_pub = self.create_publisher(MugimenduKodetzaileak, 'kodetzaileak', 10)
        
        # Entzuleak
        self.mugimendua_entzulea = self.create_subscription(
            Twist,
            'cmd_vel',
            self.mugimendua_entzulea_callback,
            10
        )

        # Zerbitzua: TCP edo UDP kontrola aldatzeko
        self.kontrol_mota = False # True --> TCP, False --> UDP
        self.kontrola_srv = self.create_service(Trigger, 'kontrol_mota', self.kontrola_aldatu_callback)

        # TCP klase aldagaiak motorrak kontrolatzeko
        self.bezero_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        try:
            self.bezero_socket.connect(("192.168.1.140", 12345))
            self.bezero_socket.setblocking(False)  # Mandar paquete sin esperar respuesta
            self.get_logger().info("TCP konexioa ezarrita 192.168.1.140:12345 helbidearekin, /cmd_vel topikoaren informazioa bidaltzen.\n")
        except Exception as e:
            self.get_logger().error(f"Ezin izan da TCP bidez konektatu: {e}")

        # UDP klase aldagaiak motorrak kontrolatzeko
        self.udp_mugimendua_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        try:
            self.udp_mugimendua_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
            self.udp_destino = ("192.168.1.140", 5004)  # Cambia IP y puerto
        except Exception as e:
            self.get_logger().error(f"Ezin izan da UDP ataka sortu: {e}")
        
        # UDP klase aldagaiak kodetzaileen informazioa jasotzeko
        self.udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        try:
            self.udp_socket.bind(("0.0.0.0", 5000))  # Escuchar en todas las interfaces, puerto 5000
            self.get_logger().info("5000 UDP portuan mugimendu motorren kodetzaileen datuen zain.")
        except Exception as e:
            self.get_logger().error(f"Ezin izan da UDP ataka ireki: {e}")

        # UDP haria hasi (threads)
        threading.Thread(target=self.receive_data_udp, daemon=True).start()


    def gelditu(self):
        # Nodoa ixterakoan robota gelditzeko funtzioa
        self.bezero_socket.send('tank_drive.off()\n'.encode())
        self.get_logger().info("mugimendu_motorrak nodoa itxi da eta motorrak gelditu dira.\n")
    
    def kontrola_aldatu_callback(self, request, response):
        # TCP (botoiak) eta UDP (joystick) arteko kontrola aldatzeko funtzioa
        self.kontrol_mota = not self.kontrol_mota
        response.success = True
        response.message = f"Kontrol-mota: {self.kontrol_mota} ({'TCP' if self.kontrol_mota else 'UDP'})"
        self.get_logger().info(response.message)
        return response

    def mugimendua_entzulea_callback(self, mezua):
        try:
            linear = mezua.linear.x
            angular = mezua.angular.z

            # Magnitud total de la orden
            total = abs(linear) + abs(angular)

            # Escala para que la suma de |linear|+|angular| sea self.abiadura
            escala = self.abiadura / total if total > self.abiadura else 1.0

            # Cálculo de velocidades
            if linear < 0.0: #para que vaya bien hacia atrás
                vel_izq = (linear + angular) * escala
                vel_der = (linear - angular) * escala
            else:
                vel_izq = (linear - angular) * escala
                vel_der = (linear + angular) * escala

            # Invertimos signo para que adelante sea negativo
            vel_izq *= -1 if self.motor_alderantzikatuak is True else 1
            vel_der *= -1 if self.motor_alderantzikatuak is True else 1

            # Redondeamos a enteros
            vel_izq = int(vel_izq)
            vel_der = int(vel_der)            

            # Abiadurak 0 badira, gelditu
            if vel_izq == 0 and vel_der == 0:
                if self.kontrol_mota:
                    self.bezero_socket.send('tank_drive.off()\n'.encode()) #TCP
                else:
                    self.udp_mugimendua_socket.sendto('tank_drive.off()\n'.encode(), self.udp_destino) # UDP
            else:
                self.get_logger().info(f"vel izq: {vel_izq}")
                self.get_logger().info(f"vel der: {vel_der}")
                cmd = f'tank_drive.on(SpeedPercent({vel_izq}),SpeedPercent({vel_der}))\n'
                if self.kontrol_mota:
                    self.bezero_socket.send(cmd.encode()) # TCP
                else:
                    self.udp_mugimendua_socket.sendto(cmd.encode(), self.udp_destino) # UDP

        except Exception as e:
            self.get_logger().error(f"Errorea TCP bidaltzean: {e}")


    def graduak_radianetara(self, degrees):
        # Graduak radianetara bihurtzeko funtzioa, [-pi, pi] tartean normalizatuta
        rad = math.radians(degrees)
        return math.remainder(rad, 2 * math.pi)

    def receive_data_udp(self):
        # Kodetzaileen irakurketak /kodetzaileak topikoan argitaratzeko funtzioa
        self.get_logger().info("Mugimendu kodetzaileak /kodetzaileak topikoan argitaratzen.")

        while rclpy.ok():
            try:
                data, addr = self.udp_socket.recvfrom(1024)  # Recibe hasta 1024 bytes
                mezua = data.decode(errors='ignore')
                #self.get_logger().info(f"Recibido desde {addr}: {mezua}")

                # Procesar el mensaje
                partes = mezua.split(',')
                if len(partes) != 4:
                    self.get_logger().warn("Formato inválido, se esperaban dos valores separados por coma")
                    continue

                try:
                    left_deg = float(partes[0])
                    right_deg = float(partes[1])
                    left_speed = float(partes[2])
                    right_speed = float(partes[3])
                except ValueError:
                    self.get_logger().warn("No se pudieron convertir los valores a float")
                    continue

                left_rad = self.graduak_radianetara(left_deg)
                right_rad = self.graduak_radianetara(right_deg)

                # Publicar en kodetzaileak
                mk = MugimenduKodetzaileak()
                mk.graduak[0] = left_deg
                mk.graduak[1] = right_deg
                mk.abiadurak[0] = left_speed
                mk.abiadurak[1] = right_speed
                self.kodetzaileak_pub.publish(mk)

            except Exception as e:
                self.get_logger().error(f"Error al recibir datos UDP: {e}")


def main(args=None):
    rclpy.init(args=args)
    mugimendu_motorrak = MugimenduMotorrak()  
    try:
        rclpy.spin(mugimendu_motorrak) 

    except KeyboardInterrupt:
        mugimendu_motorrak.get_logger().info("Erabiltzaileak nodoa gelditu du.")
        mugimendu_motorrak.gelditu()
        
    finally:
        mugimendu_motorrak.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()