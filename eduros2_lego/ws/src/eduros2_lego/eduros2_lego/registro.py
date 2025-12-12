# --- INPORTAZIOAK ---
import rclpy
from rclpy.node import Node
from rclpy.callback_groups import ReentrantCallbackGroup
import csv
import time

# ROS2 liburutegiak
from std_msgs.msg import Int32
from sensor_msgs.msg import Range
from mezuak.msg import MugimenduKodetzaileak  # tu mensaje de encoders

class DatuenErregistratzailea(Node):
    def __init__(self):
        super().__init__('datuen_erregistratzailea')
        self.get_logger().info("Nodo de registro iniciado\n")

        self.callback_group = ReentrantCallbackGroup()

        # Parámetros
        self.seinalea_gorde = True

        # Variables internas
        self.yaw_angelua = None
        self.yaw_offset = None
        self.ultrasoinu_distantzia = None
        self.pos_izq = None
        self.pos_der = None
        self.vel_izq = None
        self.vel_der = None

        # Inicializar CSV
        if self.seinalea_gorde:
            self.csv_file = "registro.csv"
            with open(self.csv_file, mode="w", newline="") as f:
                writer = csv.writer(f)
                writer.writerow([
                    "timestamp",
                    "yaw_offset",
                    "yaw",
                    "pos_izq",
                    "pos_der",
                    "vel_izq",
                    "vel_der",
                    "distancia"
                ])

        # Suscripciones
        self.sub_yaw = self.create_subscription(
            Int32, 'yaw_angelua', self.yaw_callback, 10,
            callback_group=self.callback_group)

        self.sub_range = self.create_subscription(
            Range, 'distantzia', self.range_callback, 10,
            callback_group=self.callback_group)

        self.sub_encoders = self.create_subscription(
            MugimenduKodetzaileak, '/kodetzaileak', self.encoders_callback, 10,
            callback_group=self.callback_group)

        # Timer para volcar datos periódicamente
        self.timer = self.create_timer(0.1, self.registrar_datos, callback_group=self.callback_group)

    def yaw_callback(self, msg: Int32):
        self.yaw_angelua = msg.data
        if self.yaw_offset is None:
            self.yaw_offset = self.yaw_angelua
            self.get_logger().info(f"Offset inicial yaw: {self.yaw_offset}")

    def range_callback(self, msg: Range):
        self.ultrasoinu_distantzia = msg.range

    def encoders_callback(self, msg: MugimenduKodetzaileak):
        # suponiendo que graduak = posiciones, abiadurak = velocidades
        self.pos_izq = msg.graduak[0]
        self.pos_der = msg.graduak[1]
        self.vel_izq = msg.abiadurak[0]
        self.vel_der = msg.abiadurak[1]

    def registrar_datos(self):
        if not self.seinalea_gorde:
            return
        if self.yaw_angelua is None or self.ultrasoinu_distantzia is None:
            return  # aún no tenemos datos completos

        ts = time.time()
        with open(self.csv_file, mode="a", newline="") as f:
            writer = csv.writer(f)
            writer.writerow([
                ts,
                self.yaw_offset,
                self.yaw_angelua,
                self.pos_izq,
                self.pos_der,
                self.vel_izq,
                self.vel_der,
                self.ultrasoinu_distantzia
            ])

def main(args=None):
    rclpy.init(args=args)
    nodo = DatuenErregistratzailea()
    try:
        rclpy.spin(nodo)
    except KeyboardInterrupt:
        nodo.get_logger().info("Nodo detenido por el usuario.")
    finally:
        nodo.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
