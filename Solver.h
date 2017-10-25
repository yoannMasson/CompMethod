#ifndef SOLVER_H_
#define SOLVER_H_

#include "matrix.h"

class Solver{

protected:
	Matrix computedSolution;
	double dx;
	double dt;
	double L;
	double T;
	double D;
	double Tsur;
	double Tin;



public:

	Solver(double dx, double dt, double L, double T, double D, double Tsur, double Tin );
	Matrix getComputedSolution();
	virtual Matrix computeSolution() = 0;
	~Solver(){}


};
#endif /* Solver_h */
