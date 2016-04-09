#include "../include/simulator.h"

Simulator * Simulator::instance = 0;

Simulator::Simulator() : nh("")
{
  velocity_sub = nh.subscribe("twist", 10, velocityCallbackWrapper);
}

void Simulator::velocityCallbackWrapper(const geometry_msgs::Twist::ConstPtr& vel_msg)
{
  getInstance()->velocityCallback(vel_msg);
}

void Simulator::velocityCallback(const geometry_msgs::Twist::ConstPtr& vel_msg)
{
 ROS_INFO("Joy data: %f %f %f", vel_msg->linear.x, vel_msg->linear.y, vel_msg->linear.z);
}

Simulator* Simulator::getInstance()
{
  if(instance == 0)
    instance = new Simulator;
  return instance;
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "simulator");
    Simulator::getInstance();
    ros::spin();
    return 0;
}
