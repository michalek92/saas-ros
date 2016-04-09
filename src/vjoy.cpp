#include <ros/ros.h>
#include <sensor_msgs/Joy.h>

// This is just a dummy data source used to check
// if the communication bewtween nodes works.

int main(int argc, char **argv)
{
  ros::init(argc, argv, "vjoy");
  ros::NodeHandle nh;
  ros::Publisher pub = nh.advertise<sensor_msgs::Joy>("joy", 10);
  ros::Rate rate(2);
  while(nh.ok())
  {
    std::vector<float> jebance;
    jebance.push_back(0.2);
    jebance.push_back(0.5);
    jebance.push_back(0.7);
    sensor_msgs::Joy msg;
    msg.axes=jebance;
    pub.publish(msg);
    rate.sleep();
  }
  return 0;
}
