// test ping on two machines

#include "ros/ros.h"
#include "std_msgs/Bool.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv,  "host");

    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<std_msgs::Bool>("test", 1);

    ros::Rate r(0.2);

    while (ros::ok())
    {
        std_msgs::Bool b;
        b.data = 1;
        pub.publish(b);

        ROS_INFO("host: Request sent.");

        ros::spinOnce();
        r.sleep();
    }
}