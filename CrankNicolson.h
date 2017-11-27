/*
 * CrankNicholson.h
 *
 *  Created on: 31 oct. 2017
 *      Author: yoann
 */

#ifndef CRANKNICOLSON_H_
#define CRANKNICOLSON_H_
#include "Solver.h"
#include "vector.h"

using namespace std;

class CrankNicolson: public Solver {
public:
	CrankNicolson(double dx, double dt, double L, double T, double D, double Tsur, double Tin );
	Matrix virtual computeSolution();
	virtual ~CrankNicolson();
private:
	Vector resolveOneStep(Vector bottomDiagonal,
			Vector diagonal,
			Vector upDiagonal,
			Vector resultDiagonal,
			Vector &f);
};

#endif /* CRANKNICOLSON_H_ */
