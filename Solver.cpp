#include "Solver.h"

Solver::Solver(Matrix m) {
	(*this).computedSolution = m;
}

Solver::Solver() {
	Matrix m;
	(*this).computedSolution = m;
	std::cout << "on est pas encore mort" << std::endl;
}

Solver::Solver(int nRows, int nCols){
	Matrix m(nRows,nCols);
	(*this).computedSolution = m;
}

Matrix Solver::getComputedSolution() {
	return (*this).computedSolution;
}

