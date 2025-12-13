from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare
from launch_ros.actions import Node
from launch.conditions import IfCondition, UnlessCondition
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    urdf_path = os.path.join(
        get_package_share_directory('eduros2_lego'),
        'sim',
        'robot.urdf'
    )
    
    urdf_path_arg = DeclareLaunchArgument(
        'urdf_path',
        default_value=urdf_path,
        description='Ruta al URDF'
    )

    rviz_path = os.path.join(
        get_package_share_directory('eduros2_lego'),
        'sim',
        'conf.rviz'
    )

    rviz_config_arg = DeclareLaunchArgument(
        'rviz_config',
        default_value=rviz_path,
        description='Ruta al archivo de configuración de RViz2'
    )
    
    use_gui_arg = DeclareLaunchArgument(
        'use_gui',
        default_value='false',
        description='Iniciar joint_state_publisher_gui (true/false)'
    )

    use_controller_arg = DeclareLaunchArgument(
        'use_controller',
        default_value='false',
        description='Iniciar con mando (true/false)'
    )
    
    params_file_arg = DeclareLaunchArgument(
        'params_file',
        default_value=PathJoinSubstitution([
            FindPackageShare('eduros2_lego'),
            'config',
            'params.yaml'
        ]),
        description='Ruta al archivo de parámetros YAML'
    )
    params_file = LaunchConfiguration('params_file')

    params_file_arg2 = DeclareLaunchArgument(
        'params_file',
        default_value=PathJoinSubstitution([
            FindPackageShare('gen_opt'),
            'config',
            'params.yaml'
        ]),
        description='Ruta al archivo de parámetros YAML'
    )
    params_file2 = LaunchConfiguration('params_file')

    rsp = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
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

    mugimendu_motorrak = Node(
        package='eduros2_lego',      
        executable='mugimendu_motorrak',  
        name='mugimendu_motorrak',
        output='screen',
        parameters=[params_file],
    )

    ultrasoinu_sentsorea = Node(
        package='eduros2_lego',      
        executable='ultrasoinu_sentsorea',  
        name='ultrasoinu_sentsorea',
        output='screen'
    )

    biraketa_sentsorea = Node(
        package='eduros2_lego',      
        executable='biraketa_sentsorea',  
        name='biraketa_sentsorea',
        output='screen'
    )

    joint_states = Node(
        package='eduros2_lego',      
        executable='joint_states',  
        name='joint_states',
        output='screen'
    )

    zuzen_objektuarenganaino = Node(
        package='gen_opt',      
        executable='pid_gen_opt',  
        name='pid_gen_opt',
        output='screen',
        parameters=[params_file2],
    )

    return LaunchDescription([
    urdf_path_arg,
    rviz_config_arg,
    use_gui_arg,
    use_controller_arg,
    params_file_arg, 
    rsp,
    jsp_gui,
    rviz,
    mugimendu_motorrak,
    ultrasoinu_sentsorea,
    biraketa_sentsorea,
    joint_states,
    zuzen_objektuarenganaino
])
