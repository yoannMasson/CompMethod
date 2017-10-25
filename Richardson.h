/*
 * Richardson.h
 *
 *  Created on: 25 oct. 2017
 *      Author: yoann
 */



#include "Solver.h"

class Richardson: public Solver {
public:
	Richardson(double dx, double dt, double L, double T, double D, double Tsur, double Tin );
	Matrix virtual computeSolution();
	virtual ~Richardson();
};

