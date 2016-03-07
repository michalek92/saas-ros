#include <ros/ros.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "publisher");
    ros::NodeHandle nh;
    ros::Rate rate(2); // in Hz

    while(nh.ok())
    {
        ROS_INFO("I'm ok");
        rate.sleep();
    }

    return 0;
}
