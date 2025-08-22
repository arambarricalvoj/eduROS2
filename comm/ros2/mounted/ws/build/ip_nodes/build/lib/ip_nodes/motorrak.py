# --- INPORTAZIOAK ---
# ROS2 libututegiak
import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from geometry_msgs.msg import Twist

# Beste liburutegiak
import socket
# --- INPORTAZIOAK ---

class Motorrak(Node):
    def __init__(self):
        super().__init__('motorrak') # ROS2-n izango duen izena
        self.get_logger().info("nodoa hasiarazi da\n")
        
        # Entzuleak
        self.mugimendua_entzulea = self.create_subscription(
            Twist,
            'cmd_vel',
            self.mugimendua_entzulea_callback,
            10)

        # Klase aldagaiak
        self.bezero_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.bezero_socket.connect(("192.168.1.140", 12345))
        self.bezero_socket.setblocking(False) # Mandar paquete sin esperar respuesta

    def mugimendua_entzulea_callback(self, mezua):
        if mezua.linear.x < 0.0 and mezua.angular.z == 0.0: # Aurrera
            self.bezero_socket.send(f'tank_drive.on(SpeedPercent({int(mezua.linear.x)}*(1)),SpeedPercent({int(mezua.linear.x)}*(1)))\n'.encode())
        elif mezua.linear.x > 0.0 and mezua.angular.z == 0.0: # Atzera
            self.bezero_socket.send(f'tank_drive.on(SpeedPercent({int(mezua.linear.x)}*(1)),SpeedPercent({int(mezua.linear.x)}*(1)))\n'.encode())
        elif mezua.linear.x == 0.0 and mezua.angular.z > 0.0: # Ezkerra
            self.bezero_socket.send(f'tank_drive.on(SpeedPercent({int(mezua.angular.z)}*(1)),SpeedPercent({int(mezua.angular.z)}*(-1)))\n'.encode())
        elif mezua.linear.x == 0.0 and mezua.angular.z < 0.0: # Eskuina
            self.bezero_socket.send(f'tank_drive.on(SpeedPercent({int(mezua.angular.z)}*(1)),SpeedPercent({int(mezua.angular.z)}*(-1)))\n'.encode())
        elif mezua.linear.x == 0.0 and mezua.angular.z == 0.0: # Gelditu
            self.bezero_socket.send('tank_drive.off()\n'.encode())

def main(args=None):
    rclpy.init(args=args)
    motorrak = Motorrak()
    rclpy.spin(motorrak)
    motorrak.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
