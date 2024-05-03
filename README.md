# F1Tenth_Capstone
>CSE 596 Capstone Spring 2024, F1Tenth Autonomous Racing

Mapping with SLAM then autonomously driving on the built map
### Demo: https://www.youtube.com/watch?v=7GemxeSg69k

<br /> 

## How to Run
**Source ROS prior to running any ROS2 related commands in a new terminal:** <br />
```
source /opt/ros/<ROS-DISTRO>/setup.bash
source install/local_setup.bash
```
<br />

**To build ROS packages:** <br />
```
colcon build
```
<br />

**Launch the simulation node:** <br />
```
ros2 launch f1tenth_gym_ros gym_bridge_launch.py
```
<br />

**Run waypoint logger node:** <br />

* Run:
``
ros2 run waypoint_logger waypoint_logger
``
* Drive car around the track

<br />

**Run Pure Pusuit node:** <br />
```
ros2 run pursuit_lab pure_pursuit_node.py
```
<br />

**To start F1Tenth car and slam_toolbox (requires Autoware and F1Tenth car):** <br />
* Give permissions:
``
chmod +x /LaunchSlam.sh
``
* Run:
``
./LaunchSlam.sh
``
* Drive car around the track

<br />

## Tech Stack

* ROS2 Galactic, C++, Python

