#include "Analytic.h"
#include <cmath>



Analytic::Analytic(double dx, double dt, double L, double T, double D, double Tsur, double Tin ):
Solver (dx, dt, L, T, D, Tsur, Tin){}

Matrix Analytic::computeSolution(){

	const double PI = 3.14159265;
	Matrix m = getComputedSolution();
	int nRows = m.getNrows();
	int nCols = m.getNcols();
	double sum (0.0),t(0.0),x(0.0);
	for (int i = 0; i < nCols ; i++) {
		m[0][i] = 100;
	}


	for (int i = 1; i < nRows; i++) {
		x = 0;
		t += dt;
		m[i][0] = 300;
		m[i][nCols-1] = 300;
		for (int j = 1; j < nCols-1; j++) {
			sum = 0.0;
			x += dx;
			for(int z = 1; z<100; z++){
				sum += exp(-D*(z*PI)*(z*PI)*t)*((1-(pow(-1,z)))/(z*PI))*sin(z*PI*x);
			}
			m[i][j] = Tsur+2*(Tin-Tsur)*sum;
		}
	}

	(*this).computedSolution = m;
	return m;

}


