/*
 * Laasonen.h
 *
 *  Created on: 26 oct. 2017
 *      Author: yoann
 */

#ifndef LAASONEN_H_
#define LAASONEN_H_

#include "Solver.h"

class Laasonen: public Solver {
public:
	Laasonen(double dx, double dt, double L, double T, double D, double Tsur, double Tin );
	Matrix virtual computeSolution();
	virtual ~Laasonen();
private:
	Vector resolveOneStep(Vector bottomDiagonal,
				Vector diagonal,
				Vector upDiagonal,
				Vector resultDiagonal,
				Vector &f);
};

#endif /* LAASONEN_H_ */
