import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy
from geometry_msgs.msg import Twist
from std_srvs.srv import Trigger
from rclpy.callback_groups import ReentrantCallbackGroup

class Mando(Node):
    def __init__(self):
        super().__init__('mando')
        self.get_logger().info("nodoa hasiarazi da")

        self.cb_group = ReentrantCallbackGroup()

        self.declare_parameter('abiadura', 25.0)
        self.abiadura = self.get_parameter('abiadura').value

        self.declare_parameter('threshold', 2.0)
        self.threshold = self.get_parameter('threshold').value

        self.sub = self.create_subscription(Joy, '/joy', self.callback_joy, 10)
        self.pub = self.create_publisher(Twist, '/cmd_vel', 10)

        self.deadzone = 0.2
        self.boton_stop = 0  # Índice del botón X (SOUTH) → AJUSTA según tu mando

        self.joystick_activo = True
        self.boton_stop_anterior = 0

        # Últimos valores publicados
        self.last_linear = 0.0
        self.last_angular = 0.0

        # Zerbitzua kontrol-mota aldatzeko (TCP edo UDP)
        self.kontrol_mota_srv = self.create_client(Trigger, 'kontrol_mota', callback_group=self.cb_group)
        while not self.kontrol_mota_srv.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('/kontrol_mota zerbitzuaren zain...')

    def kontrol_mota_aldatu(self):
        req = Trigger.Request()
        future = self.kontrol_mota_srv.call_async(req)
        rclpy.spin_until_future_complete(self, future)
        #future.add_done_callback(self.kontrol_mota_callback)
        return future.result()

    
    def callback_joy(self, joy_msg: Joy):
        boton_actual = joy_msg.buttons[self.boton_stop]

        # Toggle joystick activo/desactivo
        if boton_actual == 1 and self.boton_stop_anterior == 0:
            self.joystick_activo = not self.joystick_activo
            estado = "ACTIVADO" if self.joystick_activo else "DESACTIVADO"
            self.get_logger().info(f"Joystick {estado}")
            self.kontrol_mota_aldatu()
            if not self.joystick_activo:
                self.pub.publish(Twist())
                self.last_linear = 0.0
                self.last_angular = 0.0

        self.boton_stop_anterior = boton_actual

        twist = Twist()

        if self.joystick_activo:
            # Control con stick izquierdo [0], [1]
            eje_x = joy_msg.axes[3]
            eje_y = joy_msg.axes[4]

            if abs(eje_x) < self.deadzone:
                eje_x = 0.0
            if abs(eje_y) < self.deadzone:
                eje_y = 0.0

            linear = eje_y * self.abiadura
            angular = eje_x * self.abiadura

        else:
            # Control con cruceta (D-Pad)
            dpad_x = joy_msg.axes[6]  # izquierda/derecha
            dpad_y = joy_msg.axes[7]  # arriba/abajo

            linear = 0.0
            angular = 0.0

            if dpad_y == 1.0:   # Arriba
                linear = self.abiadura
            elif dpad_y == -1.0:  # Abajo
                linear = -self.abiadura

            if dpad_x == 1.0:   # Izquierda
                angular = self.abiadura
            elif dpad_x == -1.0:  # Derecha
                angular = -self.abiadura

        # Publicar solo si hay cambio significativo
        if (abs(linear - self.last_linear) > self.threshold or
            abs(angular - self.last_angular) > self.threshold):
            twist.linear.x = linear
            twist.angular.z = angular
            self.pub.publish(twist)
            self.last_linear = linear
            self.last_angular = angular

def main(args=None):
    rclpy.init(args=args)
    nodo = Mando()
    rclpy.spin(nodo)
    nodo.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
