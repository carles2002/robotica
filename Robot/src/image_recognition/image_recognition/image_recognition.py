import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from keras.models import load_model
import cv2
import numpy as np
import os
from ament_index_python.packages import get_package_share_directory

class ImageRecognitionNode(Node):
    def __init__(self):
        super().__init__('image_recognition_node')

        # Obtener la ruta del directorio del paquete
        package_share_directory = get_package_share_directory('image_recognition')

        # Rutas absolutas para los archivos
        model_path = os.path.join(package_share_directory, 'resource', 'keras_model.h5')
        labels_path = os.path.join(package_share_directory, 'resource', 'labels.txt')

        self.publisher_ = self.create_publisher(String, 'classification', 10)
        self.camera = cv2.VideoCapture(0)
        self.model = load_model(model_path, compile=False)
        
        # Leer y limpiar las etiquetas
        with open(labels_path, "r") as f:
            self.class_names = [line.strip() for line in f.readlines()]
        
        self.timer = self.create_timer(0.1, self.publish_classification)

    def publish_classification(self):
        ret, image = self.camera.read()
        if ret:
            image = cv2.resize(image, (224, 224), interpolation=cv2.INTER_AREA)
            image = np.asarray(image, dtype=np.float32).reshape(1, 224, 224, 3)
            image = (image / 127.5) - 1
            prediction = self.model.predict(image)
            index = np.argmax(prediction)
            class_name = self.class_names[index] if index < len(self.class_names) else "Unknown"
            confidence_score = float(np.round(prediction[0][index] * 100, 2))
            message = f'Class: {class_name}, Confidence: {confidence_score}%'
            self.publisher_.publish(String(data=message))

    def on_shutdown(self):
        self.camera.release()
        cv2.destroyAllWindows()

def main(args=None):
    rclpy.init(args=args)
    node = ImageRecognitionNode()
    rclpy.spin(node)
    rclpy.shutdown(callback=node.on_shutdown)

if __name__ == '__main__':
    main()
