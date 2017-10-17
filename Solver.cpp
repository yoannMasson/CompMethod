#include "Solver.h"

Solver::Solver(Matrix m) {
	(*this).computedSolution = m;
}

Solver::Solver() {
	Matrix m;
	(*this).computedSolution = m;
}

Matrix Solver::getComputedSolution() {
	return (*this).computedSolution;
}
