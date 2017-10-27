/*
 * Laasonen.cpp
 *
 *  Created on: 26 oct. 2017
 *      Author: yoann
 */

#include "Laasonen.h"

#include <cmath>



Laasonen::Laasonen(double dx, double dt, double L, double T, double D, double Tsur, double Tin ):
Solver (dx, dt, L, T, D, Tsur, Tin){}

Matrix Laasonen::computeSolution(){

	Matrix m = getComputedSolution();
	int nRows = m.getNrows();
	int nCols = m.getNcols();

	//initialisation
	for (int i = 0; i < nRows; i++) {
		for (int j = 0; j < nCols ; j++) {
			if(j == 0 || j == nCols-1){
				m[i][j] = 300;
			}else{
				m[i][j] = 100;
			}
		}
	}

	//Calcul
	for (int i = 0; i < nRows-1; i++) {
		for (int j = 1; j < nCols-1; j++) {
			m[i+1][j] = ((D*dt)/(dx*dx))*(m[i][j+1]-2*m[i][j]+m[i][j-1])+m[i][j];
		}
	}
	(*this).computedSolution = m;
	return m;
}

Laasonen::~Laasonen() {
	// TODO Auto-generated destructor stub
}

