import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy
from geometry_msgs.msg import Twist

class Mando(Node):
    def __init__(self):
        super().__init__('mando_joy')
        self.declare_parameter('abiadura', 25.0)
        self.abiadura = self.get_parameter('abiadura').value

        self.sub = self.create_subscription(Joy, '/joy', self.callback_joy, 10)
        self.pub = self.create_publisher(Twist, '/cmd_vel', 10)

        self.deadzone = 0.2
        self.boton_stop = 0  # Índice del botón X (SOUTH) → AJUSTA según tu mando

        self.joystick_activo = True
        self.boton_stop_anterior = 0

        # Últimos valores publicados
        self.last_linear = 0.0
        self.last_angular = 0.0
        self.change_threshold = 0.05

        self.get_logger().info("Nodo Mando suscrito a /joy listo ✅")

    def callback_joy(self, joy_msg: Joy):
        boton_actual = joy_msg.buttons[self.boton_stop]

        # Toggle joystick activo/desactivo
        if boton_actual == 1 and self.boton_stop_anterior == 0:
            self.joystick_activo = not self.joystick_activo
            estado = "ACTIVADO ✅" if self.joystick_activo else "DESACTIVADO 🛑"
            self.get_logger().info(f"Joystick {estado}")
            if not self.joystick_activo:
                self.pub.publish(Twist())
                self.last_linear = 0.0
                self.last_angular = 0.0

        self.boton_stop_anterior = boton_actual

        twist = Twist()

        if self.joystick_activo:
            # Control con stick izquierdo
            eje_x = joy_msg.axes[0]
            eje_y = joy_msg.axes[1]

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
        if (abs(linear - self.last_linear) > self.change_threshold or
            abs(angular - self.last_angular) > self.change_threshold):
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
