#include "matrix.h"

class Solver{

protected:
	Matrix computedSolution;

public:
	Solver(Matrix m);
	Solver(int nRows, int nCols);
	Solver();

	Matrix getComputedSolution();
	virtual Matrix computeSolution(double dt,double dx, double D, double Tsur,double Tin) = 0;
	~Solver(){}
};
