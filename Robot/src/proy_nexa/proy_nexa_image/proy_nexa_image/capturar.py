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
        self.image_sub = self.create_subscription(Image,'/camera/image_raw',self.camera_callback,QoSProfile(depth=10, reliability=ReliabilityPolicy.BEST_EFFORT))
        self.image_directory = os.path.join(os.getcwd(), 'src', 'proy_nexa', 'proy_nexa_image', 'image')

        
    def camera_callback(self,data):

        try:
            # Seleccionamos bgr8 porque es la codificacion de OpenCV por defecto
            cv_image = self.bridge_object.imgmsg_to_cv2(data, desired_encoding="bgr8")
            
        except CvBridgeError as e:
            print(e)

           
        cv2.imshow("Imagen capturada por el robot", cv_image)
        cv2.waitKey(1)   
        cv2.imwrite(os.path.join(self.image_directory, 'captured_image.jpg'), cv_image) 
        img = cv2.imread("captured_image.jpg")

        #Propiedades de la imagen
        print(type(img))
        print(img.shape) #píxeles verticales y horizontales            print(img.size)
        print(img.dtype)

        top_left_px = img[0,0,:] #esto me devuelve una lista de 3 valores (BGR) del pixel 0,0
        print(top_left_px)
        top_left_px_R = img[0,0,2] #esto me devuelve solo la componente R
        print(top_left_px_R)
        

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
