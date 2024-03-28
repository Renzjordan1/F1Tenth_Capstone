cmake_minimum_required(VERSION 3.5)
project(scan_pubsub)

#Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(std_msgs REQUIRED)

find_package(tutorial_interfaces REQUIRED)  

# add_executable(talker src/scan_pub.cpp)
# ament_target_dependencies(talker rclcpp sensor_msgs)

# install(TARGETS
#   talker
#   DESTINATION lib/${PROJECT_NAME})
  
 
# add_executable(listener src/scan_sub.cpp)
# ament_target_dependencies(listener rclcpp sensor_msgs)

# install(TARGETS
#   listener
#   DESTINATION lib/${PROJECT_NAME})

add_executable(pubsub src/scan_pubsub.cpp)
ament_target_dependencies(pubsub rclcpp sensor_msgs std_msgs tutorial_interfaces)

install(TARGETS
  pubsub
  DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME})

ament_package()
