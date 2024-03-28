cmake_minimum_required(VERSION 3.8)
project(aeb_lab)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS_RELEASE "-O3")


# find dependencies
find_package(ament_cmake REQUIRED)

find_package(ackermann_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclpy REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(std_msgs REQUIRED)


add_executable(aeb src/aeb.cpp)
ament_target_dependencies(aeb ackermann_msgs geometry_msgs nav_msgs rclcpp rclpy sensor_msgs std_msgs)

install(TARGETS
  aeb
  DESTINATION lib/${PROJECT_NAME})

ament_package()
