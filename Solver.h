#include "Matrix.h"

class Solver{

private:
	Matrix computedSolution;

public:
	Solver(Matrix m);
	Solver();

	Matrix getComputedSolution();
	virtual Matrix computeSolution(double dt,double dx,double L, double D, double Tsur,double Tin) const = 0;
};