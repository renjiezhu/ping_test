// fpga test ping

#include "ros/ros.h"
#include "std_msgs/Bool.h"


class fpga
{
public:
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<std_msgs::Bool>("receipt", 1);
    
    std_msgs::Bool msg;

    void receiveCallback(const std_msgs::BoolConstPtr &data);
};

void fpga::receiveCallback(const std_msgs::BoolConstPtr &data)
{
    ROS_INFO("fpga: Request received.");

    msg.data = 1;

    pub.publish(msg);

}

int main(int argc, char **argv)
{
    ros::init(argc, argv,  "fpga");

    fpga F;

    ros::Subscriber sub = F.nh.subscribe("test", 1, &fpga::receiveCallback, &F);

    ros::spin();

}