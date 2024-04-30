from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='proy_nexa_service',
            executable='proy_nexa_movement_server',
            output='screen'
        ),
    ])