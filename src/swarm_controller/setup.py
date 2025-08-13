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
        # Include launch files
        (os.path.join('share', package_name, 'launch'), 
         glob('launch/*.launch.py')),
        # Include world files  
        (os.path.join('share', package_name, 'worlds'), 
         glob('worlds/*.world')),
        # Include config files
        (os.path.join('share', package_name, 'config'), 
         glob('config/*.yaml') + glob('config/*.rviz')),
        # Include models
        (os.path.join('share', package_name, 'models', 'x500'), 
         glob('models/x500/*')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Shahin Team',
    maintainer_email='shahin.team@email.com',
    description='Main controller package for the ROS 2 drone swarm.',
    license='MIT',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'swarm_drone = swarm_controller.swarm_drone:main',
            'formation_controller = swarm_controller.formation_controller:main',
            'mission_executor = swarm_controller.mission_executor:main',
        ],
    },
)