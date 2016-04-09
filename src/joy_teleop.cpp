#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/Joy.h>

ros::Publisher pub;

inline float scaleJoystick(float raw)
{
  // I'm not sure what the exact values are; this method assumes
  // the joystick values to be from the 0-1 range
  return (raw - 0.5) * 4;
}

void dataCallback(const sensor_msgs::Joy::ConstPtr& message)
{
  geometry_msgs::Twist msg;

  msg.linear.x = scaleJoystick(message->axes[0]);
  msg.linear.z = scaleJoystick(message->axes[2]);

  pub.publish(msg);
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "joy_teleop");
  ros::NodeHandle nh;
  pub = nh.advertise<geometry_msgs::Twist>("twist", 10);

  // again; not sure what the topic of joy messages is
  ros::Subscriber subs = nh.subscribe("joy", 10, dataCallback);

  ros::spin();
}

