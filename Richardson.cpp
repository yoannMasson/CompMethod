/*
 * Richardson.cpp
 *
 *  Created on: 25 oct. 2017
 *      Author: yoann
 */

#include "Richardson.h"

#include <cmath>



Richardson::Richardson(double dx, double dt, double L, double T, double D, double Tsur, double Tin ):
Solver (dx, dt, L, T, D, Tsur, Tin){}

Matrix Richardson::computeSolution(){

	const double PI = 3.14159265;
	Matrix m = getComputedSolution();
	int nRows = m.getNrows();
	int nCols = m.getNcols();
	double sum (0.0),t(0.0),x(0.0);
	//initialisation
	for (int i = 0; i < nRows; i++) {
		for (int j = 0; j < nCols ; j++) {
			if(i == 0){
				m[i][j] = 100;
			}else{
				if(j == 0 || j == nCols-1){
					m[i][j] = 300;
				}else{
					m[i][j] = 100;
				}
			}
		}
	}

	//Calcul
	for (int i = 1; i < nRows-1; i++) {
		for (int j = 1; j < nCols-1; j++) {
			m[i+1][j] = (2*(dt*D)/(dx*dx))*(m[i][j+1]-2*m[i][j]+m[i][j-1])+m[i-1][j];
		}
	}

	(*this).computedSolution = m;
	return m;

}

Richardson::~Richardson() {
	// TODO Auto-generated destructor stub
}

