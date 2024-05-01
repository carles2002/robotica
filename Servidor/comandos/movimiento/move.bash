#Comando ROS2 para detenerse

#Me situo en Robot
cd ../../Robot
source install/setup.bash

#Exporto la variable ROS_DOMAIN
#export ROS_DOMAIN_ID=5

move(){
	ros2 run proy_nexa_service proy_nexa_movement_client $1
}

