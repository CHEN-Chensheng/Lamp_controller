#include "ros/ros.h"
#include "std_msgs/Float64.h"
//#include "/opt/ros/electric/stacks/dynamixel_motor/dynamixel_controllers/srv_gen/cpp/include/dynamixel_controllers/SetSpeed.h"
#include "dynamixel_controllers/SetSpeed.h"
#include "math.h"
#include <cstdlib>

#define PI 3.14159265

int main(int argc, char **argv)
{
  ros::init(argc, argv, "set_speed");

  ros::NodeHandle n;

  ros::ServiceClient client = n.serviceClient<dynamixel_controllers::SetSpeed>("/pan_controller/set_speed");
  dynamixel_controllers::SetSpeed srv;
  srv.request.speed = atof(*(argv+1));
  client.call(srv);

  return 0;
}

