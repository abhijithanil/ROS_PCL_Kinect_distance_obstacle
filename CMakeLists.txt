
##author:Abhi
cmake_minimum_required(VERSION 2.8.3)
project(test)##write ur package name

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg )
find_package(PCL 1.7 REQUIRED)
find_package(catkin REQUIRED COMPONENTS tf)
## Declare ROS messages and services
#add_message_files(DIRECTORY msg FILES Num.msg)
#add_service_files(DIRECTORY srv FILES AddTwoInts.srv)

## Generate added messages and services
#generate_messages(DEPENDENCIES std_msgs)

## Declare a catkin package
catkin_package()

include_directories(include ${catkin_INCLUDE_DIRS} ${PCL_INCLUDE_DIRS} )
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS} ${PCL_DEFINITIONS})


add_executable(pub_kfc pub.cpp)
target_link_libraries(pub_kfc ${catkin_LIBRARIES} ${OpenCV_LIBRARIES} ${PCL_LIBRARIES} )
add_dependencies(pub_kfc test_generate_messages_cpp)


add_executable(sub_kfc sub.cpp)
target_link_libraries(sub_kfc ${catkin_LIBRARIES} ${OpenCV_LIBRARIES} ${PCL_LIBRARIES} )
add_dependencies(sub_kfc test_generate_messages_cpp)






