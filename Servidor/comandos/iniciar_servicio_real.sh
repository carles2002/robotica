#Comando ROS2 para iniciar servicio

cd ../../Robot
#Exporto la variable ROS_DOMAIN
export ROS_DOMAIN_ID=5
#Inicio servicio
source install/setup.bash
ros2 launch proy_nexa_service proy_nexa_movement_server_launch.launch.py
