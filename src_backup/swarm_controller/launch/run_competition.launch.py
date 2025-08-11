import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, TimerAction, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

def generate_launch_description():
    pkg_ros_gz_sim = get_package_share_directory('ros_gz_sim')
    pkg_swarm_controller = get_package_share_directory('swarm_controller')

    world_file = LaunchConfiguration('world', default=os.path.join(pkg_swarm_controller, 'worlds', 'swarm_arena.world'))
    use_sim_time = LaunchConfiguration('use_sim_time', default='true')
    headless = LaunchConfiguration('headless', default='false')
    record_video = LaunchConfiguration('record_video', default='false')

    # Bridge configuration - FIXED
    bridge = Node(
        package='ros_gz_bridge',
        executable='parameter_bridge',
        arguments=[
            '/clock@rosgraph_msgs/msg/Clock[ignition.msgs.Clock',
            # Drone 0
            '/model/drone_0/pose@geometry_msgs/msg/Pose]ignition.msgs.Pose',
            '/model/drone_0/cmd_vel@geometry_msgs/msg/Twist]ignition.msgs.Twist',
            # Drone 1
            '/model/drone_1/pose@geometry_msgs/msg/Pose]ignition.msgs.Pose',
            '/model/drone_1/cmd_vel@geometry_msgs/msg/Twist]ignition.msgs.Twist',
            # Drone 2
            '/model/drone_2/pose@geometry_msgs/msg/Pose]ignition.msgs.Pose',
            '/model/drone_2/cmd_vel@geometry_msgs/msg/Twist]ignition.msgs.Twist',
            # Drone 3
            '/model/drone_3/pose@geometry_msgs/msg/Pose]ignition.msgs.Pose',
            '/model/drone_3/cmd_vel@geometry_msgs/msg/Twist]ignition.msgs.Twist',
        ],
        output='screen'
    )
    
    gz_server = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(pkg_ros_gz_sim, 'launch', 'gz_sim.launch.py')
        ),
        launch_arguments={'gz_args': ['-r -v 4 ', world_file], 'on_exit_shutdown': 'true'}.items()
    )

    gz_client = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(pkg_ros_gz_sim, 'launch', 'gz_sim.launch.py')
        ),
        launch_arguments={'gz_args': '-g -v 4'}.items()
    )

    initial_positions = [
        {'name': 'drone_0', 'x': '0.0', 'y': '0.0', 'z': '0.5'},
        {'name': 'drone_1', 'x': '2.0', 'y': '2.0', 'z': '0.5'},
        {'name': 'drone_2', 'x': '2.0', 'y': '-2.0', 'z': '0.5'},
        {'name': 'drone_3', 'x': '-2.0', 'y': '2.0', 'z': '0.5'}
    ]
    
    spawn_actions = []
    for drone_info in initial_positions:
        spawn_drone = Node(
            package='ros_gz_sim',
            executable='create',
            arguments=[
                '-world', 'swarm_arena',
                '-file', os.path.join(pkg_swarm_controller, 'models', 'x500', 'model.sdf'),
                '-name', drone_info['name'],
                '-x', drone_info['x'],
                '-y', drone_info['y'],
                '-z', drone_info['z']
            ],
            output='screen'
        )
        spawn_actions.append(spawn_drone)

    controller_nodes = []
    home_positions = [[0.0,0.0,5.0], [5.0,0.0,5.0], [0.0,5.0,5.0], [-5.0,0.0,5.0]]
    for i in range(4):
        is_leader = (i == 0)
        drone_node = Node(
            package='swarm_controller',
            executable='swarm_drone',
            namespace=f'drone_{i}',
            name='swarm_drone_node',
            parameters=[
                {'drone_id': i, 'use_sim_time': use_sim_time},
                {'role': 'leader' if is_leader else 'follower'},
                {'home_position': home_positions[i]}
            ],
            output='screen'
        )
        controller_nodes.append(drone_node)

    formation_controller = Node(
        package='swarm_controller',
        executable='formation_controller',
        name='formation_controller',
        parameters=[{'use_sim_time': use_sim_time, 'num_drones': 4}],
        output='screen'
    )

    mission_executor = Node(
        package='swarm_controller',
        executable='mission_executor',
        name='mission_executor',
        parameters=[{'use_sim_time': use_sim_time, 'video_recording': record_video}],
        output='screen'
    )

    return LaunchDescription([
        DeclareLaunchArgument('use_sim_time', default_value='true'),
        DeclareLaunchArgument('headless', default_value='false'),
        DeclareLaunchArgument('record_video', default_value='false'),
        gz_server,
        TimerAction(period=5.0, actions=[gz_client]),
        TimerAction(period=7.0, actions=[bridge]),
        TimerAction(period=10.0, actions=spawn_actions),
        TimerAction(period=12.0, actions=[formation_controller]),
        TimerAction(period=13.0, actions=controller_nodes),
        TimerAction(period=15.0, actions=[mission_executor]),
    ])