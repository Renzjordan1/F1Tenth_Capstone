from setuptools import setup

package_name = 'pursuit_lab'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='zzangupenn, Hongrui Zheng',
    maintainer_email='zzang@seas.upenn.edu, billyzheng.bz@gmail.com',
    description='f1tenth pure_pursuit',
    license='MIT',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
<<<<<<< HEAD
<<<<<<< HEAD
            'pursuit_node = pursuit_lab.pure_pursuit_node:main',
=======
            'pure_pursuit_node = pursuit_lab.pure_pursuit_node:main',
>>>>>>> ce1a67ebf7edb694f0f93a1943a2aeb630cdb943
=======
            'pure_pursuit_node = pursuit_lab.pure_pursuit_node:main',
>>>>>>> ce1a67ebf7edb694f0f93a1943a2aeb630cdb943
        ],
    },
)