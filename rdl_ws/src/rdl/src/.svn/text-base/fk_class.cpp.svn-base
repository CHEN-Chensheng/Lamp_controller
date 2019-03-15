#include <kdl/chain.hpp>
#include <kdl/chainfksolver.hpp>
#include <kdl/chainfksolverpos_recursive.hpp>
#include <kdl/chainjnttojacsolver.hpp>
#include <kdl/frames.hpp>
#include <kdl/frames_io.hpp>
#include <stdio.h>
#include <iostream>
#include <newmat/newmatio.h>
 
 
#define PI 3.14159265
 
    
using namespace KDL;
using namespace NEWMAT;


class FK {
    //Pointer to the kinematic chain
    KDL::Chain *chain_p;

    //Create Pointers to Solvers
    KDL::ChainFkSolverPos_recursive *fksolver_p;
    KDL::ChainJntToJacSolver *jacsolver_p;

    // Create joint array
    unsigned int nj;

    Matrix *J_p, *J_inv_p;

    public:
    double w[3];
    double J[3][3];
    double J_inv[3][3];

    FK (void) {
    	//KDL::Chain chain;
	chain_p = new KDL::Chain;

	//Kinematic Chain for the first 3 Segments
    	//Frame.DH(a, alpha, d, theta)
    	chain_p->addSegment(Segment(Joint(Joint::RotZ),Frame::DH(0, PI/2, 0.082, 0)));
    	chain_p->addSegment(Segment(Joint(Joint::RotZ),Frame::DH(0.137, 0, 0, PI/2)));
    	chain_p->addSegment(Segment(Joint(Joint::RotZ),Frame::DH(0.108, 0, 0, -PI/2)));

    	// Create solver based on kinematic chain_p
    	fksolver_p = new KDL::ChainFkSolverPos_recursive(*chain_p);
    	jacsolver_p = new KDL::ChainJntToJacSolver(*chain_p);

    	J_p = new Matrix(3,3);
    	J_inv_p = new Matrix(3, 3);
    }

    void Jnt2Cart (double q[]) {
    	// Create the frame that will contain the results
    	KDL::Frame cartpos;

    	KDL::JntArray jointpositions = JntArray(chain_p->getNrOfJoints());
	for (int i=0;i<3;i++) jointpositions(i)=q[i];

    	// Calculate forward position kinematics
    	fksolver_p->JntToCart(jointpositions, cartpos);

	for (int i=0;i<3;i++) w[i]=cartpos.p(i);
    }

    void Jnt2Jac (double q[]) {
    	KDL::Jacobian jacobian;
    	jacobian.resize(chain_p->getNrOfJoints());

    	KDL::JntArray jointpositions = JntArray(chain_p->getNrOfJoints());
	for (int i=0;i<3;i++) jointpositions(i)=q[i];

	jacsolver_p->JntToJac(jointpositions, jacobian);
	
	for (int i=0; i<3; i++) for (int j=0; j<3; j++) {
		J_p->element(i, j) = jacobian(i, j);
		J[i][j] = jacobian(i, j);
	}
    }

    void Jnt2JacInv (double q[]) {
    	Jnt2Jac(q);

	*J_inv_p = J_p->i();	

	for (int i=0; i<3; i++) for (int j=0; j<3; j++) {
		J_inv[i][j] = J_inv_p->element(i, j);
	}
    }
};

int main (void) {
    double q[3] = {0, 0, 0};
    FK obj;
    obj.Jnt2Cart(q);
    obj.Jnt2Jac(q);
    obj.Jnt2JacInv(q);

	printf("Jacobian:\n");
	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			printf("%f ", obj.J[i][j]);
		}
		printf("\n");
	}
	printf("Inverse Jacobian:\n");
	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			printf("%f ", obj.J_inv[i][j]);
		}
		printf("\n");
	}

	for (int i=0; i<3; i++) printf("%f ", obj.w[i]);
	printf("\n");

	for (int i=0; i<3; i++) printf("%f ", obj.w[i]);

	return 0;
}
