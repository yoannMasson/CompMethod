/*
 * CrankNicholson.h
 *
 *  Created on: 31 oct. 2017
 *      Author: yoann
 */

#ifndef CRANKNICHOLSON_H_
#define CRANKNICHOLSON_H_
#include "Solver.h"
#include "vector.h"

using namespace std;

class CrankNicholson: public Solver {
public:
	CrankNicholson(double dx, double dt, double L, double T, double D, double Tsur, double Tin );
	Matrix virtual computeSolution();
	virtual ~CrankNicholson();
private:
	Vector resolveOneStep(Vector bottomDiagonal,
			Vector diagonal,
			Vector upDiagonal,
			Vector resultDiagonal,
			Vector &f);
};

#endif /* CRANKNICHOLSON_H_ */
