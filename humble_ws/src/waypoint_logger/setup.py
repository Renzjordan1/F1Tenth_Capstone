from setuptools import find_packages, setup

package_name = 'waypoint_logger'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='rstole01',
    maintainer_email='renzjordan1@gmail.com',
    description='Waypoint Logger',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'waypoint_logger = waypoint_logger.waypoint_logger:main'
        ],
    },
)
