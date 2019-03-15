#include <kdl/chain.hpp>
#include <kdl/chainfksolver.hpp>
#include <kdl/chainfksolverpos_recursive.hpp>

#include <kdl/chainiksolverpos_nr.hpp>
#include <kdl/chainiksolvervel_pinv.hpp>
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
    ChainFkSolverPos_recursive fksolver_pos(chain);
    ChainIkSolverVel_pinv      iksolver_vel(chain);
    ChainIkSolverPos_NR        iksolver_pos(chain,fksolver_pos,iksolver_vel,100000,1e-5);

    // Create joint array
    unsigned int nj = chain.getNrOfJoints();
    KDL::JntArray jointpositions = JntArray(nj);

    KDL::Vector p_cart;

    KDL::JntArray q(chain.getNrOfJoints());
    KDL::JntArray q_init(chain.getNrOfJoints());
    q_init(0) = 0;
    q_init(1) = 0;
    q_init(2) = 0;
 
    // Assign some values to the joint positions
    for(unsigned int i=0;i<3;i++){
        float myinput;
        printf ("Enter  %i. Coordinate: ",i+1);
        scanf ("%e",&myinput);
        p_cart(i)=(double)myinput;
    }

    int ret = iksolver_pos.CartToJnt(q_init,Frame(p_cart),q);
    //if(ret>=0){
        std::cout << "Jointkoordinaten: " << q(0) << "  " << q(1) << "  " << q(2) <<std::endl;
        printf("%s \n","Succes, thanks KDL!");
    //}else{
    //    printf("%s \n","Error: could not calculate inverse kinematics :(");
    //}
}
