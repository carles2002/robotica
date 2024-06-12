import rclpy
from rclpy.node import Node
from std_msgs.msg import String

class ImageRecognitionSubscriber(Node):
    def __init__(self):
        super().__init__('image_recognition_subscriber')
        self.subscription = self.create_subscription(
            String,
            'classification',
            self.listener_callback,
            10
        )
        self.subscription  # Prevent unused variable warning

    def listener_callback(self, msg):
        print('I heard: "%s"' % msg.data)

def main(args=None):
    rclpy.init(args=args)
    node = ImageRecognitionSubscriber()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
