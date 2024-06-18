import rclpy
import cv2
import numpy as np
from cv_bridge import CvBridge, CvBridgeError
from sensor_msgs.msg import Image
from rclpy.node import Node
from rclpy.qos import ReliabilityPolicy, QoSProfile
import os
from ament_index_python.packages import get_package_share_directory

class Ros2OpenCVImageConverter(Node):   

    def __init__(self):

        super().__init__('Ros2OpenCVImageConverter')
        
        self.bridge_object = CvBridge()
        self.image_sub = self.create_subscription(Image,'/image',self.camera_callback,QoSProfile(depth=10, reliability=ReliabilityPolicy.reliable))
        self.image_directory = os.path.join(os.getcwd(), 'src', 'proy_nexa', 'proy_nexa_image', 'image')
        self.image_directory_sepia = os.path.join(os.getcwd(), 'src', 'proy_nexa', 'proy_nexa_image', 'image_sepia')

        
    def camera_callback(self,data):

        try:
            # Seleccionamos bgr8 porque es la codificacion de OpenCV por defecto
            cv_image = self.bridge_object.imgmsg_to_cv2(data, desired_encoding="bgr8")
            cv2.imwrite(os.path.join(self.image_directory, 'image_raw.jpg'), cv_image) 
            
        except CvBridgeError as e:
            print(e)

           
        sepia_img = self.apply_sepia(cv_image)
        cv2.imshow("Imagen con filtro sepia", sepia_img)
        cv2.waitKey(1)        
        cv2.imwrite(os.path.join(self.image_directory_sepia, 'image_sepia.jpg'), sepia_img) 
        

        
    def apply_sepia(self, image):

        sepia_filter = np.array([[0.272, 0.534, 0.131],
                                 [0.349, 0.686, 0.168],
                                 [0.393, 0.769, 0.189]])
        
        sepia_image = cv2.transform(image, sepia_filter)
        sepia_image = np.clip(sepia_image, 0, 255).astype(np.uint8)        
        return sepia_image
        

def main(args=None):

    rclpy.init(args=args)    
    img_converter_object = Ros2OpenCVImageConverter()    
       
    try:
        rclpy.spin(img_converter_object)
    except KeyboardInterrupt:
        img_converter_object.destroy_node()
        print("Fin del programa!")
    
    cv2.destroyAllWindows() 
    

if __name__ == '__main__':
    main()
