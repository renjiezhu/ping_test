//  test ping

#include "ros/ros.h"
#include "std_msgs/Bool.h"

void receiveCallback(const std_msgs::BoolConstPtr &data)
{
    ROS_INFO("host: Receipt received.");
}

int main(int argc, char **argv)
{
    ros::init(argc, argv,  "rec");

    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("receipt", 1, receiveCallback);

    ros::spin();

}