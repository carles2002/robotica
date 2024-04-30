from launch import LaunchDescription
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration
from launch.actions import DeclareLaunchArgument

def generate_launch_description():
    my_distancia = LaunchConfiguration('my_distancia', default='1')
    return LaunchDescription([
        Node(
            package='proy_nexa_show_msg',
            executable='proy_nexa_show_msg_param',
            output='screen',
            parameters=[
               {'my_distancia': my_distancia},
                {'my_velocidad':0.13}
            ]),
    ])