#include "Analytic.h"



Analytic::Analytic(): Solver(){}

Matrix Analytic::computeSolution(double dt, double dx, double D, double Tsur, double Tin){

	int timeLimit (0.5 / 0.01);
	int matrixLimit = (1 / 0.05);
	Matrix m = getComputedSolution();
	for (int i = 0; i < matrixLimit ; i++) {
		m[0][i] = 100;
	}
	for (int i = 1; i < timeLimit; i++) {
		m[i][0] = 300;
		m[i][matrixLimit] = 300;
		for (int j = 1; j < timeLimit-1; j++) {
			m[i][j] = 0;
		}
	}
}


