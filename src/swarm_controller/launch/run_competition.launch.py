import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import (
    DeclareLaunchArgument, IncludeLaunchDescription,
    GroupAction, TimerAction, ExecuteProcess, OpaqueFunction
)
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node, PushRosNamespace
from launch_ros.substitutions import FindPackageShare

def launch_setup(context, *args, **kwargs):
    """Setup function to handle dynamic launch configuration"""
    
    pkg_swarm_controller = get_package_share_directory('swarm_controller')
    world_path = os.path.join(pkg_swarm_controller, 'worlds', 'swarm_arena.world')
    params_file = os.path.join(pkg_swarm_controller, 'config', 'swarm_params.yaml')
    model_path = os.path.join(pkg_swarm_controller, 'models')

    # Setup Gazebo environment
    if 'GZ_SIM_RESOURCE_PATH' in os.environ:
        os.environ['GZ_SIM_RESOURCE_PATH'] += os.pathsep + model_path
    else:
        os.environ['GZ_SIM_RESOURCE_PATH'] = model_path

    launch_actions = []

    # Gazebo launch with proper cleanup
    gazebo_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('ros_gz_sim'),
                'launch', 'gz_sim.launch.py'
            ])
        ]),
        launch_arguments={
            'gz_args': f'-r -v4 {world_path}',
            'on_exit_shutdown': 'true'
        }.items()
    )
    launch_actions.append(gazebo_launch)

    # Clock bridge with error handling
    clock_bridge = Node(
        package='ros_gz_bridge',
        executable='parameter_bridge',
        arguments=['/clock@rosgraph_msgs/msg/Clock[gz.msgs.Clock'],
        output='screen',
        respawn=True,
        respawn_delay=2.0
    )
    launch_actions.append(TimerAction(period=3.0, actions=[clock_bridge]))

    # Drone setup
    num_drones = 4
    spawn_positions = [
        [-4.5, 0.0, 0.3], [-1.5, 0.0, 0.3],
        [1.5, 0.0, 0.3], [4.5, 0.0, 0.3]
    ]

    for i in range(num_drones):
        drone_name = f'x500_{i}'
        namespace = f'drone_{i}'
        pos = spawn_positions[i]
        
        # Spawn drone in Gazebo
        spawn_drone = ExecuteProcess(
            cmd=['gz', 'service', '-s', '/world/swarm_arena/create',
                 '--reqtype', 'gz.msgs.EntityFactory',
                 '--reptype', 'gz.msgs.Boolean',
                 '--timeout', '5000',
                 '--req', f'sdf_filename: "{os.path.join(model_path, 'x500', 'model.sdf')}" '
                          f'name: "{drone_name}" '
                          f'pose: {{position: {{x: {pos[0]} y: {pos[1]} z: {pos[2]}}}}}'],
            output='screen'
        )

        # Drone control group with improved error handling
        drone_group = GroupAction([
            PushRosNamespace(namespace),
            
            # Parameter bridge with retry
            Node(
                package='ros_gz_bridge',
                executable='parameter_bridge',
                arguments=[
                    f'/model/{drone_name}/odometry@nav_msgs/msg/Odometry[gz.msgs.Odometry',
                    f'/model/{drone_name}/cmd_vel@geometry_msgs/msg/Twist]gz.msgs.Twist',
                    f'/model/{drone_name}/enable@std_msgs/msg/Bool]gz.msgs.Boolean',
                ],
                remappings=[
                    (f'/model/{drone_name}/odometry', 'odom'),
                    (f'/model/{drone_name}/cmd_vel', 'cmd_vel'),
                    (f'/model/{drone_name}/enable', 'enable'),
                ],
                output='screen',
                respawn=True,
                respawn_delay=2.0,
                parameters=[{'use_sim_time': True}]
            ),
            
            # Drone controller with improved shutdown handling
            Node(
                package='swarm_controller',
                executable='swarm_drone',
                name='controller',
                parameters=[{
                    'drone_id': i, 
                    'role': 'leader' if i == 0 else 'follower',
                    'use_sim_time': True,
                    'max_velocity': 2.0,
                    'safety_distance': 3.5,
                    'home_position': [pos[0], pos[1], 5.0]
                }],
                output='screen',
                respawn=False,  # Don't respawn to avoid RCL shutdown issues
                on_exit=lambda info, *args: print(f"Drone {i} exited with code {info.returncode}")
            )
        ])

        # Staggered deployment
        delayed_spawn = TimerAction(period=float(5 + 3*i), actions=[spawn_drone])
        delayed_drone = TimerAction(period=float(8 + 3*i), actions=[drone_group])
        
        launch_actions.extend([delayed_spawn, delayed_drone])

    # Formation controller with delay
    formation_controller = TimerAction(
        period=25.0,
        actions=[Node(
            package='swarm_controller', 
            executable='formation_controller',
            parameters=[params_file],
            output='screen',
            respawn=False
        )]
    )
    launch_actions.append(formation_controller)

    # Mission executor with delay
    mission_executor = TimerAction(
        period=35.0,
        actions=[Node(
            package='swarm_controller', 
            executable='mission_executor',
            parameters=[params_file],
            output='screen',
            respawn=False
        )]
    )
    launch_actions.append(mission_executor)

    return launch_actions

def generate_launch_description():
    return LaunchDescription([
        DeclareLaunchArgument('use_sim_time', default_value='true'),
        DeclareLaunchArgument('headless', default_value='false'),
        DeclareLaunchArgument('record_video', default_value='false'),
        
        OpaqueFunction(function=launch_setup)
    ])