import rclpy
from rclpy.node import Node
import random
from sensor_msgs.msg import Range

class UltrasonicPublisher(Node):
    def __init__(self):
        super().__init__('ultrasonic_sim')
        self.publisher_ = self.create_publisher(Range, 'ultrasonic', 10)
        timer_period = 1.0  # segundos
        self.timer = self.create_timer(timer_period, self.timer_callback)

        # Mensaje base
        self.msg = Range()
        self.msg.header.frame_id = 'ultrasonic'  # Debe coincidir con el link del URDF
        self.msg.radiation_type = Range.ULTRASOUND
        self.msg.field_of_view = 0.5   # ~28 grados
        self.msg.min_range = 0.10      # 10 cm
        self.msg.max_range = 1.00      # 1 m

    def timer_callback(self):
        self.msg.header.stamp = self.get_clock().now().to_msg()
        self.msg.range = random.uniform(0.10, 1.00)
        self.get_logger().info(f'Distancia ultrasónico: {self.msg.range:.2f} m')
        self.publisher_.publish(self.msg)

def main(args=None):
    rclpy.init(args=args)
    node = UltrasonicPublisher()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
