#include <kdl/chain.hpp>
#include <kdl/chainfksolver.hpp>
#include <kdl/chainfksolverpos_recursive.hpp>
#include <kdl/frames.hpp>
#include <kdl/frames_io.hpp>
#include <stdio.h>
#include <iostream>
 
using namespace KDL;
 
#define PI 3.14159265
 
int main( int argc, char** argv )
{
    //Definition of a kinematic chain & add segments to the chain
    KDL::Chain chain;

    //chain.addSegment(Segment(Joint(Joint::RotZ),Frame::Identity()));
    chain.addSegment(Segment(Joint(Joint::RotZ),Frame(Rotation::RPY(0, -PI/2, 0), Vector(0, 0, 0.082))));
    chain.addSegment(Segment(Joint(Joint::RotZ),Frame(Rotation::RPY(0, PI, 0), Vector(0.137, 0, 0))));
    chain.addSegment(Segment(Joint(Joint::RotZ),Frame(Rotation::Identity(), Vector(0, 0.108, 0))));
 
    // Create solver based on kinematic chain
    ChainFkSolverPos_recursive fksolver(chain);
 
    // Create joint array
    unsigned int nj = chain.getNrOfJoints();
    KDL::JntArray jointpositions = JntArray(nj);
 
    // Assign some values to the joint positions
    for(unsigned int i=0;i<nj;i++){
        float myinput;
        printf ("Enter the position of joint %i: ",i);
        scanf ("%e",&myinput);
        jointpositions(i)=(double)myinput;
    }
 
    // Create the frame that will contain the results
    KDL::Frame cartpos;    
 
    // Calculate forward position kinematics
    bool kinematics_status;
    kinematics_status = fksolver.JntToCart(jointpositions,cartpos);
    if(kinematics_status>=0){
        std::cout << cartpos <<std::endl;
        printf("%s \n","Succes, thanks KDL!");
    }else{
        printf("%s \n","Error: could not calculate forward kinematics :(");
    }
}
