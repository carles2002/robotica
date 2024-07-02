#Inicio
sudo apt-get install sshpass
clear
sshpass -p turtlebot ssh ubuntu@192.168.0.64
#[Terminal SSH]
export ROS_DOMAIN_ID=5
ros2 run image_tools cam2image --ros-args -p burger_mode:=false -p frequency:=10.0 -p reliability:=reliable
