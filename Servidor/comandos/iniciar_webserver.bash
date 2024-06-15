# Este archivo nos arranca el servidor web_video_server para poder visualizar la cámara con ros
cd ../../Robot/src/

git clone --branch ros2 https://github.com/RobotWebTools/web_video_server
git clone https://github.com/fkie/async_web_server_cpp.git

colcon build --packages-select async_web_server_cpp
colcon build --packages-select web_video_server

clear # Quitar comentarios del git clone y colcon build

source install/setup.bash
source install/web_video_server/share/web_video_server/local_setup.bash

export ROS_DOMAIN_ID=5
ros2 run web_video_server web_video_server

#http://0.0.0.0:8080/stream?topic=/image&type=mjpeg&width=300&height=200
