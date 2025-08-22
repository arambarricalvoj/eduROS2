# Copyright 2016 Open Source Robotics Foundation, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import rclpy
from rclpy.node import Node
from std_msgs.msg import String
import socket

class MinimalSubscriber(Node):
    def __init__(self):
        super().__init__('minimal_subscriber')
        self.subscription = self.create_subscription(
            String,
            'key_press',  # Cambiado para coincidir con el tópico del publicador
            self.listener_callback,
            10)
        self.subscription  # prevent unused variable warning

        self.client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.client_socket.connect(("192.168.1.140", 12345))
        self.client_socket.setblocking(False) # Mandar paquete sin esperar respuesta

    def listener_callback(self, msg):
        self.get_logger().info('I heard: "%s"' % msg.data)

        if msg.data == 'Tecla flecha arriba presionada':
            self.client_socket.send('tank_drive.on(SpeedPercent(25*(-1)),SpeedPercent(25*(-1)))\n'.encode())
        elif msg.data == 'Tecla flecha abajo presionada':
            self.client_socket.send('tank_drive.on(SpeedPercent(25*(1)),SpeedPercent(25*(1)))\n'.encode())
        elif msg.data == 'Tecla flecha izquierda presionada':
            self.client_socket.send('tank_drive.on(SpeedPercent(25*(1)),SpeedPercent(25*(-1)))\n'.encode())
        elif msg.data == 'Tecla flecha derecha presionada':
            self.client_socket.send('tank_drive.on(SpeedPercent(25*(-1)),SpeedPercent(25*(1)))\n'.encode())
        elif msg.data == 'Tecla flecha liberada':
            self.client_socket.send('tank_drive.off()\n'.encode())

def main(args=None):
    rclpy.init(args=args)
    minimal_subscriber = MinimalSubscriber()
    rclpy.spin(minimal_subscriber)
    minimal_subscriber.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
