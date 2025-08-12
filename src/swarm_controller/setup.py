from setuptools import setup, find_packages
import os
from glob import glob

package_name = 'swarm_controller'

setup(
    name=package_name,
    version='1.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        
        # Install launch files
        (os.path.join('share', package_name, 'launch'), glob('launch/*.launch.py')),
        
        # Install world files  
        (os.path.join('share', package_name, 'worlds'), glob('worlds/*.world')),
        
        # Install config files
        (os.path.join('share', package_name, 'config'), glob('config/*')),
        
        # Install model files with proper structure
        (os.path.join('share', package_name, 'models/x500'), glob('models/x500/*.sdf')),
        (os.path.join('share', package_name, 'models/x500'), glob('models/x500/*.config') or []),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Competition Team',
    maintainer_email='competition@example.com',
    description='Swarm drone controller for competition',
    license='MIT',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'swarm_drone = swarm_controller.swarm_drone:main',
            'formation_controller = swarm_controller.formation_controller:main',
            'mission_executor = swarm_controller.mission_executor:main',
            'swarm_leader = swarm_controller.swarm_drone:main',
            'swarm_follower = swarm_controller.swarm_drone:main',
        ],
    },
)