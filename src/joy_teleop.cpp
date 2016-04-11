#include "../include/joy_teleop.h"

JoyTeleop::JoyTeleop() : nh_(""), nh_local("~") {
  joy_sub_ = nh_.subscribe("joy", 10, &JoyTeleop::joyCallback, this);
  vel_pub_ = nh_.advertise<geometry_msgs::Twist>("velocity", 10);


  //nh_.getParam() other way
  nh_local.param<double>("linear_gain", k_v,2.0);
  nh_local.param<double>("angular_gain", k_w,2.0);

 // ROS_INFO_STREAM("Linear "<<k_v);
 // ROS_INFO_STREAM("Angular "<<k_w);

  ros::spin();
}

void JoyTeleop::joyCallback(const sensor_msgs::Joy::ConstPtr& joy_msg) {
  geometry_msgs::Twist msg;
  msg.linear.x = k_v * joy_msg->axes[1];
  msg.angular.z = k_w * joy_msg->axes[0];

  vel_pub_.publish(msg);
}

int main(int argc, char** argv) {
  ros::init(argc, argv, "joy_teleop");
  JoyTeleop J;
  return 0;
}
