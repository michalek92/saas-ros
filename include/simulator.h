#include <ros/ros.h>
#include <geometry_msgs/Pose2D.h>
#include <geometry_msgs/Twist.h>

class Simulator
{
  public:
    Simulator();
    void publish();
    static Simulator *getInstance();

  private:
    // I know, the singleton approach is ugly.
    // We cant pass a member function as callback directly though...
    static void velocityCallbackWrapper(const geometry_msgs::Twist::ConstPtr& vel_msg);
    static Simulator *instance;

    void velocityCallback(const geometry_msgs::Twist::ConstPtr& vel_msg);
    ros::NodeHandle nh;
    ros::Subscriber velocity_sub;
    ros::Publisher pose_pub;

    geometry_msgs::Pose2D pose;
    geometry_msgs::Twist twist;
};
