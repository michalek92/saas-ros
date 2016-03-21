#include <ros/ros.h>
#include <std_msgs/String.h>
#include <string>

void chatterCallback(const std_msgs::String::ConstPtr &msg)
{
    char bfr[128];
    sprintf(bfr, "Received %s", msg->data.c_str());
    ROS_INFO(bfr);
}

int main(int argc, char ** argv)
{
    ros::init(argc, argv, "listener");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("chatter", 10, chatterCallback);

    ros::spin();

    return 0;
}
