# --- INPORTAZIOAK ---
# ROS2 liburutegiak
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from std_msgs.msg import Int32
from sensor_msgs.msg import Range
from rclpy.callback_groups import ReentrantCallbackGroup
import csv
import time

# Beste liburutegiak
# --- INPORTAZIOAK ---


class ZuzenObjektuarenganaino(Node):
    def __init__(self):
        super().__init__('zuzen_objektuarenganaino')  # ROS2-n izango duen izena
        self.get_logger().info("nodoa hasiarazi da\n")

        self.nodoa_itxi = False

        self.callback_group = ReentrantCallbackGroup()

        self.declare_parameter('abiadura', 25.0)
        self.abiadura = self.get_parameter('abiadura').value
        self.aurreko_abiadura = False

        self.declare_parameter('eten_distantzia', 0.15)
        self.eten_distantzia = self.get_parameter('eten_distantzia').value

        self.declare_parameter('desbideratzeak_zuzendu', False)
        self.desbideratzeak_zuzendu = self.get_parameter('desbideratzeak_zuzendu').value
        self.get_logger().info(f"desbideratzeak_zuzendu: {self.desbideratzeak_zuzendu}")
        self.desbideratzeak_zuzendu = True

        self.declare_parameter('kp', 5.31)
        self.kp = self.get_parameter('kp').value

        self.declare_parameter('seinalea_gorde', "False")
        self.seinalea_gorde = self.get_parameter('seinalea_gorde').value 
        self.seinalea_gorde = True

        if self.seinalea_gorde:
            self.csv_file = f"registro_kp_{self.kp}_gen.csv"
            with open(self.csv_file, mode="w", newline="") as f:
                writer = csv.writer(f)
                writer.writerow(["timestamp", "offset", "yaw", "error"])

        self.yaw_angelua = None
        self.offset = None
        self.ultrasoinu_distantzia = None

        # Argitaratzaileak
        self.cmd_vel_pub = self.create_publisher(Twist, 'cmd_vel', 10)

        # Timer-a: 0.1 segunduro funtzioa exekutatzen da
        self.timer = self.create_timer(0.1, self.mugitu_objektuarenganaino, callback_group=self.callback_group) # 0.1 segunduro
        
        # Entzuleak
        self.biraketa_sentsorea_entzulea = self.create_subscription(Int32,'yaw_angelua',self.biraketa_sentsorea_callback,10,callback_group=self.callback_group)
        self.ultrasoinu_sentsorea_entzulea = self.create_subscription(Range,'distantzia',self.ultrasoinu_sentsorea_callback,10,callback_group=self.callback_group)

    def biraketa_sentsorea_callback(self, mezua: Int32):
        try:
            self.yaw_angelua = mezua.data

            if not self.offset:
                self.offset = self.yaw_angelua   
                self.get_logger().info(f"Offset: {self.offset}")             
        
        except Exception as e:
            self.get_logger().info(f"Errorea biraketa sentsorearen callback: {e}")

    def ultrasoinu_sentsorea_callback(self, mezua: Range):
        try:
            self.ultrasoinu_distantzia = mezua.range
        
        except Exception as e:
            self.get_logger().info(f"Errorea biraketa sentsorearen callback: {e}")

    def mugitu_objektuarenganaino(self):
        error = (self.yaw_angelua - self.offset) * self.kp
        error_percent = error * 100 / 360

        # Guardar en CSV si está activado
        if self.seinalea_gorde:
            ts = time.time()
            with open(self.csv_file, mode="a", newline="") as f:
                writer = csv.writer(f)
                writer.writerow([ts, self.offset, self.yaw_angelua, error])

        self.get_logger().info(f"Current: {self.yaw_angelua}") 
        self.get_logger().info(f"Error: {error}") 
        self.get_logger().info(f"Error pct: {error_percent}") 
        
        if self.ultrasoinu_distantzia is None:
            return  # Ez dugu oraindik distantziarik

        if self.ultrasoinu_distantzia > self.eten_distantzia:
            # Aurrera mugitu
            if not self.aurreko_abiadura:
                self.aurreko_abiadura = True if not self.desbideratzeak_zuzendu else False
                mezua = Twist()
                mezua.linear.x = self.abiadura * (100 - error_percent) # Abiadura finkoa
                mezua.angular.z = self.abiadura * error_percent  # Abiadura finkoa
                self.cmd_vel_pub.publish(mezua)
        else:
            # Gelditu eta nodoa itxi
            mezua = Twist()  # 0 abiadura
            self.cmd_vel_pub.publish(mezua)
            self.get_logger().info("Objektua hurbil dago. Nodoa gelditzen...")
            self.nodoa_itxi = True
            self.timer.cancel()


def main(args=None):
    rclpy.init(args=args)
    zuzen_objektuarenganaino = ZuzenObjektuarenganaino()  
    try:
        while rclpy.ok():
            rclpy.spin_once(zuzen_objektuarenganaino, timeout_sec=0.1)
            if zuzen_objektuarenganaino.nodoa_itxi:
                break

    except KeyboardInterrupt:
        zuzen_objektuarenganaino.get_logger().info("Erabiltzaileak nodoa gelditu du.")

    finally:
        zuzen_objektuarenganaino.destroy_node()
        zuzen_objektuarenganaino.get_logger().info("Nodoa amaitu da.")
        rclpy.shutdown()


if __name__ == '__main__':
    main()