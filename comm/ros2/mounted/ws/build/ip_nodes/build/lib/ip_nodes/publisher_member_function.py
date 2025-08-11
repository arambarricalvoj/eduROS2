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
from pynput import keyboard

class KeyboardPublisher(Node):
    def __init__(self):
        super().__init__('keyboard_publisher')
        self.publisher_ = self.create_publisher(String, 'key_press', 10)
        self.key_pressed = False

    def on_press(self, key):
        msg = String()
        if key == keyboard.Key.up:
            msg.data = 'Tecla flecha arriba presionada'
        elif key == keyboard.Key.down:
            msg.data = 'Tecla flecha abajo presionada'
        elif key == keyboard.Key.left:
            msg.data = 'Tecla flecha izquierda presionada'
        elif key == keyboard.Key.right:
            msg.data = 'Tecla flecha derecha presionada'

        self.publisher_.publish(msg)
        self.get_logger().info('Publishing: "%s"' % msg.data)

    def on_release(self, key):
        if key == keyboard.Key.up or key == keyboard.Key.down or key == keyboard.Key.left or key == keyboard.Key.right:
            msg = String()
            msg.data = 'Tecla flecha liberada'
            self.publisher_.publish(msg)
            self.get_logger().info('Publishing: "%s"' % msg.data)

def main(args=None):
    rclpy.init(args=args)
    keyboard_publisher = KeyboardPublisher()

    listener = keyboard.Listener(
        on_press=keyboard_publisher.on_press,
        on_release=keyboard_publisher.on_release
    )
    listener.start()

    rclpy.spin(keyboard_publisher)

    listener.stop()
    keyboard_publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
