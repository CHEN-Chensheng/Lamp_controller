#include "ros/ros.h"
#include "rosbag/bag.h"
#include "rdl/jangs.h"


int main(int argc, char **argv) {
 ros::init(argc, argv, "bag_write", ros::init_options::NoSigintHandler);
 ros::NodeHandle n;


 rosbag::Bag bag("test.bag", rosbag::bagmode::Write);
 rdl::jangs joint_angles;
 joint_angles.q[0] = 42;
 joint_angles.q[1] = 3.12345;
 joint_angles.q[2] = 42;
 joint_angles.q[3] = 42;
 joint_angles.q[4] = 42;

 bag.write("joint_angles", ros::Time::now(), joint_angles);
 bag.close();

 return 0;
}
