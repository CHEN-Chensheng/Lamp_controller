#include "ros/ros.h"
#include <cstdlib>
#include <iostream>
#include "math.h"

int main(int argc, char**argv) {
  //Cartesian Coordinates in 0-Frame
  double w[3] = {atof(*(argv+1)), atof(*(argv+2)), atof(*(argv+3))};

  //Fixed Parameters
  double d1=0.082;
  double a2=0.137;
  double a3=0.108;

  //Begin Calculations of inverse kinematics
  double h = w[2] - d1;
  double r = sqrt(pow(w[0], 2.0) + pow(w[1], 2.0));
  double l = sqrt(pow(h, 2.0) + pow(r, 2.0));

  //Calculate gamma
  double beta = atan2(h, r);
  double gamma = acos((pow(l, 2) - pow(a2, 2) + pow(a3, 2))/(2*l*a3));
  double alpha = asin(a3/a2*sin(gamma));

  double theta1 = atan2(w[1], w[0]);
  double theta2 = alpha + beta;
  double theta3 = -(alpha + gamma);



  ROS_INFO("l=%f a2+a3=%f a2-a3=%f h=%f r=%f theta1=%f theta2=%f theta3=%f", l, a2+a3, a2-a3, h, r, theta1, theta2, theta3);
}
