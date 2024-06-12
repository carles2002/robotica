from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='image_recognition',
            executable='image_recognition',
            name='image_recognition_node'
        ),
        Node(
            package='image_recognition',
            executable='image_recognition_subscriber',
            name='image_recognition_subscriber_node'
        )
    ])
