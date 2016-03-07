#include <ros/ros.h>
#include <std_msgs/String.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "publisher");
    ros::NodeHandle nh;
    ros::Rate rate(2); // in Hz
    ros::Publisher ourPub = nh.advertise<std_msgs::String>("chatter", 10);

    while(nh.ok())
    {
        ROS_INFO("I'm ok");
        std_msgs::String msg;
        msg.data = "ajaja";
        ourPub.publish(msg);
        rate.sleep();
    }

    return 0;
}
