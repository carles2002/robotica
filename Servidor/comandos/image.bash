#Colocarse en el Robot
cd ../../Robot
source install/setup.bash

#ROS_DOMAIN_ID
export ROS_DOMAIN_ID=5

#Comando a ejecutar
ros2 run proy_nexa_image capture_image