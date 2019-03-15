#include <ros/ros.h>
#include "dynamixel_controllers/TorqueEnable.h"
#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "turn_off_torques");

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<dynamixel_controllers::TorqueEnable>("/ax12_controller_3/torque_enable");
  dynamixel_controllers::TorqueEnable srv;
  srv.request.torque_enable = false;
  if (client.call(srv))
  {
    ROS_INFO("Success!");
  }
  else
  {
    ROS_ERROR("Failed to call service add_two_ints");
    return 1;
  }

  return 0;
}
