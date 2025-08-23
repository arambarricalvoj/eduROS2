from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from launch.conditions import IfCondition

def generate_launch_description():
    urdf_path_arg = DeclareLaunchArgument(
        'urdf_path',
        default_value='/home/javierac/mounted/ws/src/sim/robot.urdf',
        description='Ruta al URDF'
    )

    rviz_config_arg = DeclareLaunchArgument(
        'rviz_config',
        default_value='/home/javierac/mounted/ws/src/sim/conf.rviz',
        description='Ruta al archivo de configuración de RViz2'
    )

    use_gui_arg = DeclareLaunchArgument(
        'use_gui',
        default_value='true',
        description='Iniciar joint_state_publisher_gui (true/false)'
    )

    rsp = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        # Tal cual lo pediste: pasando la ruta del URDF como argumento (mostrará un warning de compatibilidad).
        arguments=[LaunchConfiguration('urdf_path')],
        output='screen'
    )

    jsp_gui = Node(
        package='joint_state_publisher_gui',
        executable='joint_state_publisher_gui',
        name='joint_state_publisher_gui',
        output='screen',
        condition=IfCondition(LaunchConfiguration('use_gui'))
    )

    rviz = Node(
        package='rviz2',
        executable='rviz2',
        arguments=['-d', LaunchConfiguration('rviz_config')],
        output='screen'
    )

    teklatua = Node(
        package='ip_nodes',         
        executable='teklatua',      
        name='teklatua',
        output='screen',
        parameters=[{
            'abiadura': 25.0
        }]
    )

    mugimendu_motorrak = Node(
        package='ip_nodes',      
        executable='mugimendu_motorrak',  
        name='mugimendu_motorrak',
        output='screen'
    )

    ultrasoinu_sentsorea = Node(
        package='ip_nodes',      
        executable='ultrasoinu_sentsorea',  
        name='ultrasoinu_sentsorea',
        output='screen'
    )

    return LaunchDescription([urdf_path_arg, rviz_config_arg, use_gui_arg, rsp, jsp_gui, rviz, teklatua, mugimendu_motorrak, ultrasoinu_sentsorea])

