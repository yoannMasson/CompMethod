#include "Solver.h"


Solver::Solver(double dx, double dt, double L, double T, double D, double Tsur, double Tin){
	(*this).dx = dx;
	(*this).dt = dt;
	(*this).L = L;
	(*this).T = T;
	(*this).D = D;
	(*this).Tsur = Tsur;
	(*this).Tin = Tin;
	int nRows = T/dt;
	int nCols = L/dx;
	Matrix m(nRows,nCols);
	(*this).computedSolution = m;
}

Matrix Solver::getComputedSolution() {

	return (*this).computedSolution;
}

