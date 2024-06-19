import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import numpy as np
import cv2

class ImagePublisher(Node):
    def __init__(self):
        super().__init__('image_publisher')
        self.publisher_ = self.create_publisher(Image, '/camera/image_raw', 10)
        self.timer = self.create_timer(0.1, self.publish_image)
        self.bridge = CvBridge()

    def publish_image(self):
        # Crear una imagen aleatoria
        image = np.random.randint(0, 256, (480, 640, 3), dtype=np.uint8)
        # Convertir la imagen a un mensaje de ROS
        image_msg = self.bridge.cv2_to_imgmsg(image, "bgr8")
        # Publicar la imagen
        self.publisher_.publish(image_msg)
        self.get_logger().info('Published random image')

def main(args=None):
    rclpy.init(args=args)
    node = ImagePublisher()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
