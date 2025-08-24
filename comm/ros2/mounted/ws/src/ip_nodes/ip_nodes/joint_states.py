import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
from std_msgs.msg import Int32
from mezuak.msg import MugimenduKodetzaileak
import math

class JointStatesKontrolatzailea(Node):
    def __init__(self):
        super().__init__('joint_states_kontrolatzailea')

        # Publicador de joint_states
        self.joint_pub = self.create_publisher(JointState, 'joint_states', 10)

        # Subscripciones
        self.create_subscription(MugimenduKodetzaileak, 'kodetzaileak', self.kodetzaileak_cb, 10)
        self.create_subscription(Int32, 'yaw_angelua', self.yaw_cb, 10)

        # Variables para almacenar últimos valores
        self.left_rad = None
        self.right_rad = None
        self.gyro_rad = None

        self.get_logger().info("Nodo agregador de joint_states iniciado.")

    def graduak_radianetara(self, degrees):
        """Convierte grados a radianes, normalizados en el rango [-pi, pi]."""
        rad = math.radians(degrees)
        return math.remainder(rad, 2 * math.pi)
    
    def kodetzaileak_cb(self, msg: MugimenduKodetzaileak):
        # Convertir grados a radianes y normalizar
        self.left_rad = self.graduak_radianetara(msg.graduak[0])
        self.right_rad = self.graduak_radianetara(msg.graduak[1])
        self.publicar_joint_states_si_listo()

    def yaw_cb(self, msg: Int32):
        # Convertir grados a radianes y aplicar signo si es necesario
        self.gyro_rad = -math.radians(msg.data)
        self.publicar_joint_states_si_listo()

    def publicar_joint_states_si_listo(self):
        # Solo publicamos si tenemos datos de ambos
        if self.left_rad is not None and self.right_rad is not None and self.gyro_rad is not None:
            js = JointState()
            js.header.stamp = self.get_clock().now().to_msg()
            js.name = [
                'base_left_wheel_joint',
                'base_right_wheel_joint',
                'base_gyro_joint'
            ]
            js.position = [
                self.left_rad,
                self.right_rad,
                self.gyro_rad
            ]
            self.joint_pub.publish(js)

def main(args=None):
    rclpy.init(args=args)
    node = JointStatesKontrolatzailea()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
