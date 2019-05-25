cmake_minimum_required(VERSION 2.8.3)
project(humanoid_robot_base)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  rospy
  rviz
  sensor_msgs
  std_msgs
  roscpp
  rosserial_arduino
  rosserial_client
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES humanoid_robot_base
#  CATKIN_DEPENDS roscpp rospy rosserial_arduino rosserial_client
#  DEPENDS system_lib
)

rosserial_generate_ros_lib(
  PACKAGE rosserial_arduino
  SCRIPT make_libraries.py
)

add_dependencies(${PROJECT_NAME}_ros_lib ${PROJECT_NAME}_generate_messages)
add_dependencies(${PROJECT_NAME}_ros_lib ${catkin_EXPORTED_TARGETS})

rosserial_configure_client(
  DIRECTORY src
  TOOLCHAIN_FILE ${ROSSERIAL_ARDUINO_TOOLCHAIN}
)

rosserial_add_client_target(src humanoid_robot_base ALL)
rosserial_add_client_target(src humanoid_robot_base-upload)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)
