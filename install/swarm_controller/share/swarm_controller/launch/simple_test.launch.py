#!/usr/bin/env python3

from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        # Formation Controller
        Node(
            package='swarm_controller',
            executable='formation_controller',
            name='formation_controller',
            output='screen'
        ),
        
        # Leader Node
        Node(
            package='swarm_controller',
            executable='swarm_leader',
            name='swarm_leader_0',
            parameters=[{'drone_id': 0}],
            output='screen'
        ),
        
        # Follower Nodes
        Node(
            package='swarm_controller', 
            executable='swarm_follower',
            name='swarm_follower_1',
            parameters=[{'drone_id': 1}],
            output='screen'
        ),
        
        Node(
            package='swarm_controller',
            executable='swarm_follower', 
            name='swarm_follower_2',
            parameters=[{'drone_id': 2}],
            output='screen'
        ),
        
        Node(
            package='swarm_controller',
            executable='swarm_follower',
            name='swarm_follower_3', 
            parameters=[{'drone_id': 3}],
            output='screen'
        )
    ])
