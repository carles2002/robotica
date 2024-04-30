#Inicio
sudo apt-get install sshpass
sshpass -p turtlebot ssh ubuntu@192.168.0.64
#[Terminal SSH]
ros2 launch turtlebot3_bringup robot.launch.py
export ROS_DOMAIN_ID=5

