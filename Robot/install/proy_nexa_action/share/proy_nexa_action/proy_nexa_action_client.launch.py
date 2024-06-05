from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='proy_nexa_action',
            executable='proy_nexa_action_client_girafa',
            output='screen'
        ),
        Node(
            package='proy_nexa_action',
            executable='proy_nexa_action_client_mono',
            output='screen'
        )
    ])