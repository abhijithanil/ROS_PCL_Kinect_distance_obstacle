#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/filters/crop_box.h>
#include <ros/ros.h>

using namespace::std;
ros::Publisher pub;
/* you can find explanation to this code in 
*http://wiki.ros.org/pcl/Tutorials
*The catch is, in the tutorial they are subscribing to camera/depth/points but you are suppose to 
*subscribe to /camera/depth_registered/points
*Don't forget to launch openni.launch before running this code.
*/
void cloud_cb (const sensor_msgs::PointCloud2ConstPtr& input){
sensor_msgs::PointCloud2 output;
pcl::PCLPointCloud2* cloud =new pcl::PCLPointCloud2;
pcl::PCLPointCloud2ConstPtr cloudPtr(cloud);
pcl::PCLPointCloud2 cloud_filtered;
pcl_conversions::toPCL(*input, *cloud);
pcl::VoxelGrid<pcl::PCLPointCloud2> sor;
sor.setInputCloud (cloudPtr);
sor.setLeafSize(0.01,0.01,0.01);
sor.filter (cloud_filtered);
pcl_conversions::fromPCL(cloud_filtered, output);
pub.publish (output);
}
/***/
int main (int argc, char** argv){
ros::init (argc, argv,"pub_kfc");
ros::NodeHandle nh;
ros::Subscriber sub = nh.subscribe ("/camera/depth_registered/points", 1,cloud_cb);
pub = nh.advertise<sensor_msgs::PointCloud2> ("volexFilterPoints", 1);
ros::spin ();
return 0;
}
