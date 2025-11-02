# --- INPORTAZIOAK ---
# ROS2 libututegiak
import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from geometry_msgs.msg import Twist

# Beste liburutegiak
from pynput import keyboard
# --- INPORTAZIOAK ---

class TeklatuArgitaratzailea(Node):
    def __init__(self):
        super().__init__('teklatua') # ROS2-n izango duen izena
        self.get_logger().info("nodoa hasiarazi da\n")
        self.get_logger().info("Teklatuaren geziak sakatu robota mugitzeko.")
        self.get_logger().info("/cmd_vel topikoan argitaratzen mugimendu motorren mugimenduak.\n")

        # Parametroak
        self.declare_parameter('abiadura', 25.0)
        self.abiadura = self.get_parameter('abiadura').value

        # Argitaratzaileak
        self.argitaratzailea = self.create_publisher(Twist, '/cmd_vel', 10)

        # Klase aldagaiak
        self.key_pressed = False

    def on_press(self, key):
        mezua = Twist()
        if key == keyboard.Key.up:
            # Tecla flecha arriba presionada
            mezua.linear.x = self.abiadura
            mezua.angular.z = 0.0

        elif key == keyboard.Key.down:
            # Tecla flecha abajo presionada
            mezua.linear.x = self.abiadura * (-1)
            mezua.angular.z = 0.0

        elif key == keyboard.Key.left:
            # Tecla flecha izquierda presionada
            mezua.linear.x = 0.0
            mezua.angular.z = self.abiadura

        elif key == keyboard.Key.right:
            # Tecla flecha derecha presionada
            mezua.linear.x = 0.0
            mezua.angular.z = self.abiadura * (-1)

        self.argitaratzailea.publish(mezua)

    def on_release(self, key):
        if key == keyboard.Key.up or key == keyboard.Key.down or key == keyboard.Key.left or key == keyboard.Key.right:
            mezua = Twist()
            mezua.linear.x = 0.0
            mezua.angular.z = 0.0
            self.argitaratzailea.publish(mezua)

def main(args=None):
    rclpy.init(args=args)
    teklatua = TeklatuArgitaratzailea()

    teklatu_entzulea = keyboard.Listener(
        on_press=teklatua.on_press,
        on_release=teklatua.on_release
    )
    teklatu_entzulea.start()

    rclpy.spin(teklatua)

    teklatu_entzulea.stop()
    teklatua.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
