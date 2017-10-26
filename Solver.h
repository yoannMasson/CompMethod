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
	Matrix getComputedSolution() ;
	double getDT();
	virtual Matrix computeSolution() = 0;
	~Solver(){}

	friend std::ostream& operator<<(std::ostream& os, Solver& m );


};
#endif /* Solver_h */
