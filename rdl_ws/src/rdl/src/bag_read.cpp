#include "ros/ros.h"
#include "ros/time.h"
#include "rosbag/bag.h"
#include "rosbag/view.h"
#include "rdl/jangs.h"
#include <boost/foreach.hpp>

#include <cstdlib>

int main(int argc, char **argv) {
 ros::init(argc, argv, "bag_read", ros::init_options::NoSigintHandler);
 ros::NodeHandle n;

 rosbag::Bag bag("/home/fabian/ROS/rdl/data/motion1.bag");
 rosbag::View view(bag, rosbag::TopicQuery("joint_angles"));

 float q[view.size()][5];
 int c=0;

 BOOST_FOREACH(rosbag::MessageInstance const m, view) {
  rdl::jangs::ConstPtr i = m.instantiate<rdl::jangs>();
  if (i != NULL) {
   /*
   std::cout << "J1: " << i->q[0] << "   ";
   std::cout << "J2: " << i->q[1] << "   ";
   std::cout << "J3: " << i->q[2] << "   ";
   std::cout << "J4: " << i->q[3] << "   ";
   std::cout << "J5: " << i->q[4] << std::endl;
   */
   //std::cout << "Size: " << view.size() << std::endl;
   q[c][0] = i->q[0];
   q[c][1] = i->q[1];
   q[c][2] = i->q[2];
   q[c][3] = i->q[3];
   q[c][4] = i->q[4];
   c++;
  }
 }
 bag.close();

 int size = sizeof(q)/sizeof(float)/5;

 for (int i=0; i<size ; i++) {
  std::cout << "J1: " << q[i][0] << "   ";
  std::cout << "J2: " << q[i][1] << "   ";
  std::cout << "J3: " << q[i][2] << "   ";
  std::cout << "J4: " << q[i][3] << "   ";
  std::cout << "J5: " << q[i][4] << std::endl;
  
 }

 return 0;
}
