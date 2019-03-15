#include <kdl/chain.hpp>
#include <kdl/chainfksolver.hpp>
#include <kdl/chainfksolverpos_recursive.hpp>
#include <kdl/chainjnttojacsolver.hpp>
#include <kdl/frames.hpp>
#include <kdl/frames_io.hpp>
#include <stdio.h>
#include <newmat/newmatio.h>
 
using namespace KDL;
using namespace NEWMAT;
 
#define PI 3.14159265
 
int main( int argc, char** argv )
{
    //Definition of a kinematic chain & add segments to the chain
    KDL::Chain chain;

    /*
    chain.addSegment(Segment(Joint(Joint::RotZ),Frame(Rotation::RPY(PI/2, 0, 0), Vector(0, 0, 0.082))));
    chain.addSegment(Segment(Joint(Joint::RotZ),Frame(Rotation::RPY(0, 0, PI/2), Vector(0, 0.137, 0))));
    chain.addSegment(Segment(Joint(Joint::RotZ),Frame(Rotation::RPY(0, 0, -PI/2), Vector(0, -0.108, 0))));
    */

    //Frame.DH(a, alpha, d, theta)
    chain.addSegment(Segment(Joint(Joint::RotZ),Frame::DH(0, PI/2, 0.082, 0)));
    chain.addSegment(Segment(Joint(Joint::RotZ),Frame::DH(0.137, 0, 0, PI/2)));
    chain.addSegment(Segment(Joint(Joint::RotZ),Frame::DH(0.108, 0, 0, -PI/2)));
 
    // Create solver based on kinematic chain
    ChainFkSolverPos_recursive fksolver(chain);
    ChainJntToJacSolver jacsolver (chain); 	

 
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
    KDL::Jacobian jacobian;
    
    jacobian.resize(chain.getNrOfJoints());
 
    // Calculate forward position kinematics
    bool kinematics_status;
    kinematics_status = fksolver.JntToCart(jointpositions, cartpos);
    jacsolver.JntToJac(jointpositions, jacobian);

    Matrix J(3,3), J_inv(3,3);
    for (int i=1; i<4; i++) for (int j=1; j<4; j++) J(i, j) = jacobian(i-1, j-1);
    J_inv = J.i();



    if(kinematics_status>=0){
        printf("%s \n","Cartpos:");
        std::cout << cartpos <<std::endl;
	printf("Jacobian:\n");
	for (int i=1; i<4; i++) {
		for (int j=1; j<4; j++) {
			printf("%f ", J(i, j));
		}
		printf("\n");
	}
	printf("Inverse Jacobian:\n");
	for (int i=1; i<4; i++) {
		for (int j=1; j<4; j++) {
			printf("%f ", J_inv(i, j));
		}
		printf("\n");
	}

	for (int i=0; i<3; i++) printf("%f ", cartpos.p(i));
	printf("\n");


    }else{
        printf("%s \n","Error: could not calculate forward kinematics :(");
    }
}
