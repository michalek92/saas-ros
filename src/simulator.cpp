#include "../include/simulator.h"

Simulator::Simulator() : nh_(""), TP(0.01) {
  vel_sub_ = nh_.subscribe("velocity", 10, &Simulator::velocityCallback, this);
  pose_pub_ = nh_.advertise<geometry_msgs::Pose2D>("pose", 10);

  ros::Rate rate(100);
  while (ros::ok()) {
    pose_.x += velocity_.linear.x * cos(pose_.theta) * TP;
    pose_.y += velocity_.linear.x * sin(pose_.theta) * TP;
    pose_.theta += velocity_.angular.z * TP;

    pose_pub_.publish(pose_);
  }
}

void Simulator::velocityCallback(const geometry_msgs::Twist::ConstPtr& vel_msg) {
  velocity_ = *vel_msg;
}

int main(int argc, char** argv) {
  ros::init(argc, argv, "simulator");
  Simulator S;
  return 0;
}
