# --- IMPORTACIONES ---
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
import threading
from inputs import get_gamepad
# --- IMPORTACIONES ---


class Mando(Node):
    def __init__(self):
        super().__init__('mando')
        self.get_logger().info("Nodo iniciado: mando DualShock4")

        # Parámetro de velocidad
        self.declare_parameter('abiadura', 25.0)
        self.abiadura = self.get_parameter('abiadura').value

        # Publicador
        self.pub = self.create_publisher(Twist, '/cmd_vel', 10)

        # Hilo para leer el mando
        self.hilo_mando = threading.Thread(target=self.leer_mando, daemon=True)
        self.hilo_mando.start()

    # --- MANDO con hilo ---
    def leer_mando(self):
        while rclpy.ok():
            try:
                events = get_gamepad()
                for event in events:
                    msg = Twist()
                    # Pulsación
                    if event.code == 'BTN_NORTH' and event.state == 1:
                        msg.linear.x = -self.abiadura
                        self.pub.publish(msg)
                    elif event.code == 'BTN_SOUTH' and event.state == 1:
                        msg.linear.x = self.abiadura
                        self.pub.publish(msg)
                    elif event.code == 'BTN_WEST' and event.state == 1:
                        msg.angular.z = self.abiadura
                        self.pub.publish(msg)
                    elif event.code == 'BTN_EAST' and event.state == 1:
                        msg.angular.z = -self.abiadura
                        self.pub.publish(msg)

                    # Soltar botón → STOP
                    elif event.code in ['BTN_SOUTH', 'BTN_EAST', 'BTN_WEST', 'BTN_NORTH'] and event.state == 0:
                        self.get_logger().info("STOP")
                        self.pub.publish(Twist())

            except Exception:
                pass  # No hay eventos o no hay mando conectado


def main(args=None):
    rclpy.init(args=args)
    nodo = Mando()
    rclpy.spin(nodo)
    nodo.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
