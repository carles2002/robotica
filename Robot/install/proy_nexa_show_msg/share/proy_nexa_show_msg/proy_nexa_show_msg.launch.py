from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='proy_nexa_show_msg',
            executable='proy_nexa_show_msg',
            output='screen'),
    ])