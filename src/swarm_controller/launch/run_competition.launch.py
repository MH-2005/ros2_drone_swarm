import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, TimerAction, ExecuteProcess
from launch.substitutions import LaunchConfiguration
from launch.conditions import IfCondition, UnlessCondition
from launch_ros.actions import Node

def generate_launch_description():
    pkg_swarm_controller = get_package_share_directory('swarm_controller')
    
    # Launch arguments
    world_file = LaunchConfiguration('world_file')
    use_sim_time = LaunchConfiguration('use_sim_time')
    headless = LaunchConfiguration('headless')
    record_video = LaunchConfiguration('record_video')
    
    world_file_path = os.path.join(pkg_swarm_controller, 'worlds', 'swarm_arena.world')
    
    # Gazebo simulation
    gazebo_server = ExecuteProcess(
        cmd=['gz', 'sim', '-r', '-s', world_file_path, '--verbose', '4'],
        output='screen',
        name='gazebo_server'
    )
    
    gazebo_client = ExecuteProcess(
        cmd=['gz', 'sim', '-g', '--verbose', '4'],
        output='screen',
        name='gazebo_client',
        condition=UnlessCondition(headless)
    )
    
    # ROS-Gazebo bridge for communication
    bridge_node = Node(
        package='ros_gz_bridge',
        executable='parameter_bridge',
        name='ros_gz_bridge',
        arguments=[
            '/clock@rosgraph_msgs/msg/Clock[gz.msgs.Clock',
            '/model/drone_0/pose@geometry_msgs/msg/PoseStamped[gz.msgs.Pose',
            '/model/drone_0/cmd_vel@geometry_msgs/msg/Twist]gz.msgs.Twist',
            '/model/drone_1/pose@geometry_msgs/msg/PoseStamped[gz.msgs.Pose',
            '/model/drone_1/cmd_vel@geometry_msgs/msg/Twist]gz.msgs.Twist',
            '/model/drone_2/pose@geometry_msgs/msg/PoseStamped[gz.msgs.Pose',
            '/model/drone_2/cmd_vel@geometry_msgs/msg/Twist]gz.msgs.Twist',
            '/model/drone_3/pose@geometry_msgs/msg/PoseStamped[gz.msgs.Pose',
            '/model/drone_3/cmd_vel@geometry_msgs/msg/Twist]gz.msgs.Twist',
        ],
        output='screen',
        parameters=[{'use_sim_time': use_sim_time}]
    )
    
    # Spawn drones at initial positions
    drone_spawns = []
    drone_positions = [
        {'id': 0, 'x': 0.0, 'y': 0.0, 'z': 0.3},
        {'id': 1, 'x': 3.0, 'y': 0.0, 'z': 0.3},
        {'id': 2, 'x': 0.0, 'y': 3.0, 'z': 0.3},
        {'id': 3, 'x': -3.0, 'y': 0.0, 'z': 0.3}
    ]
    
    model_file = os.path.join(pkg_swarm_controller, 'models', 'x500', 'model.sdf')
    
    for drone in drone_positions:
        spawn_cmd = ExecuteProcess(
            cmd=[
                'gz', 'service', '-s', '/world/swarm_arena/create',
                '--reqtype', 'gz.msgs.EntityFactory',
                '--reptype', 'gz.msgs.Boolean',
                '--timeout', '10000',
                '--req',
                f'sdf_filename: "{model_file}", '
                f'name: "drone_{drone["id"]}", '
                f'pose: {{ position: {{ x: {drone["x"]}, y: {drone["y"]}, z: {drone["z"]} }} }}'
            ],
            output='screen'
        )
        drone_spawns.append(spawn_cmd)
    
    # Swarm controller nodes
    drone_controllers = []
    home_positions = [[0.0, 0.0, 5.0], [3.0, 0.0, 5.0], [0.0, 3.0, 5.0], [-3.0, 0.0, 5.0]]
    
    for i in range(4):
        role = 'leader' if i == 0 else 'follower'
        controller = Node(
            package='swarm_controller',
            executable='swarm_drone',
            name=f'drone_{i}_controller',
            namespace=f'drone_{i}',
            parameters=[
                {'drone_id': i},
                {'role': role},
                {'home_position': home_positions[i]},
                {'max_velocity': 2.5},
                {'safety_distance': 3.5},
                {'use_sim_time': use_sim_time}
            ],
            remappings=[
                ('pose', f'/model/drone_{i}/pose'),
                ('cmd_vel', f'/model/drone_{i}/cmd_vel')
            ],
            output='screen'
        )
        drone_controllers.append(controller)
    
    # Formation manager
    formation_manager = Node(
        package='swarm_controller',
        executable='formation_controller',
        name='formation_manager',
        parameters=[
            {'num_drones': 4},
            {'formation_timeout': 120.0},
            {'position_tolerance': 1.2},
            {'use_sim_time': use_sim_time}
        ],
        output='screen'
    )
    
    # Mission coordinator
    mission_coordinator = Node(
        package='swarm_controller',
        executable='mission_executor',
        name='mission_coordinator',
        parameters=[
            {'video_recording': record_video},
            {'video_output_dir': './videos/'},
            {'mission_timeout': 180.0},
            {'use_sim_time': use_sim_time}
        ],
        output='screen'
    )
    
    return LaunchDescription([
        DeclareLaunchArgument('world_file', default_value=world_file_path),
        DeclareLaunchArgument('use_sim_time', default_value='true'),
        DeclareLaunchArgument('headless', default_value='false'),
        DeclareLaunchArgument('record_video', default_value='true'),
        
        gazebo_server,
        TimerAction(period=4.0, actions=[gazebo_client]),
        TimerAction(period=6.0, actions=[bridge_node]),
        TimerAction(period=8.0, actions=drone_spawns),
        TimerAction(period=12.0, actions=[formation_manager]),
        TimerAction(period=14.0, actions=drone_controllers),
        TimerAction(period=18.0, actions=[mission_coordinator]),
    ])