#Comando ROS2 para iniciar servicio

cd ../../Robot
#Exporto la variable ROS_DOMAIN
export ROS_DOMAIN_ID=5
source install/setup.bash
ros2 launch rosbridge_server rosbridge_websocket_launch.xml