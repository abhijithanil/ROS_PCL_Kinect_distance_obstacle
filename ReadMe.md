https://answers.ros.org/question/237717/how-to-find-distance-and-angle-bw-each-points-in-a-point-cloud-and-the-kinect-sensor/
how to find distance and angle b/w each points in a point cloud and the Kinect sensor

Question: 
Using the code provided in ROS PCL tutorial I subscribed to sensor message and generated a point cloud. 
Now I want to know how to find out the distance and angle b/w the point in the point cloud and the camera.
There is a misconception that point (x,y,z) in which z gives the distance from the camera to a point.
If anybody got a solution, please post the answer in detail.

Solution:
I figured a way to find out the point which is closer to the camera from the point cloud.
Before reading my code I would recommend you have a better understanding of coordinate frame conventions for the camera.

Step to run
Steps to run
run each steps on seperate terminals
abhi@abhi-Envy:~$  roscore
abhi@abhi-Envy:~$  roslaunch openni_launch openni.launch
abhi@abhi-Envy:~$  cd ~/catkin_ws //change to ur catkin workspace
abhi@abhi-Envy:~$  catkin_make// compiling the codes
abhi@abhi-Envy:~$  source devel/setup.bash and abhi@abhi-Envy:~$ rosrun <ur packagename> pub_kfc
abhi@abhi-Envy:~$  rosrun test pub_kfc // i gave test as my packagename
abhi@abhi-Envy:~$  source devel/setup.bash and abhi@abhi-Envy:~$ rosrun <ur packagename> sub_kfc
abhi@abhi-Envy:~$  rosrun test sub_kfc // i gave test as my packagename      

Now if you need to view what kinect sees then use
abhi@abhi-Envy:~$  rosrun rviz rviz and Add topic subscibe to topic :volexFilterPoints  

and if you are connected to turtlebot and need to visualize.. use 
abhi@abhi-Envy:~$  roslaunch turtlebot_rviz_launchers view_robot.launch 
