/*
 * DufortFrankel.h
 *
 *  Created on: 27 oct. 2017
 *      Author: yoann
 */

#ifndef DUFORTFRANKEL_H_
#define DUFORTFRANKEL_H_

#include "Solver.h"

class DufortFrankel: public Solver {
public:
	DufortFrankel(double dx, double dt, double L, double T, double D, double Tsur, double Tin );
	Matrix virtual computeSolution();
	virtual ~DufortFrankel();
};

#endif /* DUFORTFRANKEL_H_ */
