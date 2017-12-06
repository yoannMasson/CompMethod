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


	Matrix m = getComputedSolution();
	int nRows = m.getNrows();
	int nCols = m.getNcols();

	//initialisation
	for (int i = 0; i < nRows; i++) {
		for (int j = 0; j < nCols ; j++) {
			if(j == 0 || j == nCols-1){
				m[i][j] = Tsur;
			}else{
				m[i][j] = Tin;
			}
		}
	}

	//Calcul
	for (int i = 0; i < nRows-1; i++) {
		if(i==0){// When i==0 m[i-1] raise an error so we treat this case separatly
			for (int j = 1; j < nCols-1; j++) {
				m[i+1][j] = (2*(dt*D)/(dx*dx))*(m[i][j+1]-2*m[i][j]+m[i][j-1])+Tin;
			}
		}else{
			for (int j = 1; j < nCols-1; j++) {
				m[i+1][j] = (2*(dt*D)/(dx*dx))*(m[i][j+1]-2*m[i][j]+m[i][j-1])+m[i-1][j];
			}
		}

	}
	(*this).computedSolution = m;
	return m;

}

Richardson::~Richardson() {
	// TODO Auto-generated destructor stub
}

