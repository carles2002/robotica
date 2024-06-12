from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration

def generate_launch_description():
    return LaunchDescription([
        DeclareLaunchArgument(
            'use_camera',  # Nombre del argumento
            default_value='true',  # Valor por defecto
            description='Use camera for image input'  # Descripción
        ),
        Node(
            package='image_recognition',
            executable='image_recognition',
            name='image_recognition_node',
            parameters=[{'use_camera': LaunchConfiguration('use_camera').perform()}]  # Cómo se pasa el parámetro al nodo
        )
    ])
