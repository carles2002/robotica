import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from sensor_msgs.msg import Image
from keras.models import load_model
import cv2
import numpy as np
import os
from ament_index_python.packages import get_package_share_directory
from cv_bridge import CvBridge, CvBridgeError

class ImageRecognitionNode(Node):
    def __init__(self):
        super().__init__('image_recognition_node')

        # Declarar y obtener el parámetro 'use_camera' y 'use_robot_camera'
        self.use_camera = self.declare_parameter('use_camera', False).get_parameter_value().bool_value
        self.use_robot_camera = self.declare_parameter('use_robot_camera', True).get_parameter_value().bool_value

        # Obtener la ruta del directorio del paquete
        package_share_directory = get_package_share_directory('image_recognition')
        model_path = os.path.join(package_share_directory, 'resource', 'keras_model.h5')
        labels_path = os.path.join(package_share_directory, 'resource', 'labels.txt')
        self.image_path = os.path.join(package_share_directory, 'resource', 'input_image.jpg')

        self.publisher_ = self.create_publisher(String, 'classification', 10)

        # Inicializar cámara, cámara del robot o leer imagen estática basada en el parámetro
        if self.use_camera:
            self.get_logger().info("Using USB camera.")
            self.camera = cv2.VideoCapture(0)
        elif self.use_robot_camera:
            self.get_logger().info("Using robot camera.")
            self.bridge = CvBridge()
            self.image_sub = self.create_subscription(
                Image,
                '/camera/image_raw',
                self.camera_callback,
                10
            )
            self.latest_image = None
        else:
            self.get_logger().info("Using static image.")
            self.static_image = cv2.imread(self.image_path)
            if self.static_image is None:
                self.get_logger().error(f"Failed to read image from {self.image_path}")
            self.execution_count = 0  # Contador de ejecuciones para imagen estática

        self.model = load_model(model_path, compile=False)
        with open(labels_path, "r") as f:
            self.class_names = [line.strip() for line in f.readlines()]

        self.timer = self.create_timer(0.1, self.publish_classification)

    def camera_callback(self, msg):
        try:
            self.latest_image = self.bridge.imgmsg_to_cv2(msg, "bgr8")
        except CvBridgeError as e:
            self.get_logger().error(f"Failed to convert image: {e}")

    def publish_classification(self):
        if self.use_camera:
            ret, image = self.camera.read()
            if not ret:
                self.get_logger().error("Failed to capture image from USB camera.")
                return
        elif self.use_robot_camera:
            if self.latest_image is None:
                self.get_logger().warning("No image received from robot camera yet.")
                return
            image = self.latest_image
        else:
            if self.execution_count >= 5:  # Cancelar el temporizador después de 5 ejecuciones
                self.timer.cancel()
                self.get_logger().info("Reached maximum static image classification limit.")
                return
            image = self.static_image.copy()
            self.execution_count += 1  # Incrementar el contador de ejecuciones

        image = cv2.resize(image, (224, 224), interpolation=cv2.INTER_AREA)
        image = np.asarray(image, dtype=np.float32).reshape(1, 224, 224, 3)
        image = (image / 127.5) - 1
        prediction = self.model.predict(image)
        index = np.argmax(prediction)
        class_name = self.class_names[index] if index < len(self.class_names) else "Unknown"
        confidence_score = float(np.round(prediction[0][index] * 100, 2))

        # Publicar solo si la confianza es mayor al 95%
        if confidence_score > 98:
            message = f'Class: {class_name}, Confidence: {confidence_score}%'
            self.publisher_.publish(String(data=message))

    def on_shutdown(self):
        if self.use_camera:
            self.camera.release()
        cv2.destroyAllWindows()

def main(args=None):
    rclpy.init(args=args)
    node = ImageRecognitionNode()
    rclpy.spin(node)
    node.on_shutdown()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
