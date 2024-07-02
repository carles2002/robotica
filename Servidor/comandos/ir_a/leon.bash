#Comando ROS2 para ir al león

#Me situo en Robot
cd ../../Robot
source install/setup.bash

#Exporto la variable ROS_DOMAIN
export ROS_DOMAIN_ID=5
path=$HOME/repositorio2/Robot/src/proy_nexa/pro_nexa_nav2_system/config/my_map_real.yaml
ros2 service call /map_server/load_map nav2_msgs/srv/LoadMap "{map_url: $path}"
ros2 run proy_nexa_nav2_system proy_nexa_initial_pose_pub
ros2 launch proy_nexa_action proy_nexa_action_client_leon.launch.py 
