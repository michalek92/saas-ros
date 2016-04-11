#include <ros/ros.h>
#include <std_msgs/String.h>

int main(int argc, char** argv) {
  ros::init(argc, argv, "publisher");
  ros::NodeHandle nh;

  ros::Publisher our_pub = nh.advertise<std_msgs::String>("chatter", 10);

  ros::Rate rate(2); // Hz

  while (nh.ok()) {
    std_msgs::String our_msg;
    our_msg.data = "Hello";

    ROS_INFO("I'm ok!");
    our_pub.publish(our_msg);
    rate.sleep();
  }

  return 0;
}
