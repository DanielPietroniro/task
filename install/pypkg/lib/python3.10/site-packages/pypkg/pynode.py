#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from example_interfaces.msg import String


class PyNode(Node): 
    def __init__(self):
        super().__init__("pynode") 
        self.publisher_ = self.create_publisher(String, "message", 10)
        self.timer_= self.create_timer(0.5, self.publish_message)
        self.get_logger().info("messenger started")

    def publish_message(self):
        msg = String()
        msg.data = "hello"
        self.publisher_.publish(msg)
        
def main(args=None):
    rclpy.init(args=args)
    node = PyNode() 
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()