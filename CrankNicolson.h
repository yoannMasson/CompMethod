

#ifndef CRANKNICOLSON_H_
#define CRANKNICOLSON_H_

/*
 * CrankNicholson.h
 *
 *  Created on: 31 oct. 2017
 *      Author: yoann
 *
 *
 *	This class inherits from Solver and provide an approximated solution of the heat diffusion equation using Crank & Nicholson's implicit scheme
 */

#include "Solver.h"
#include "vector.h"

using namespace std;

class CrankNicolson: public Solver {
public:

	//CONSTRUCTOR
	/**
	 * Construcs a solver of the problem using Crank-Nicolson method
	 */
	CrankNicolson(double dx/**< double. distance between two space steps */,
			 double dt/**< double. time between two time steps */,
			 double L/**< double. width of the 1D material to consider */,
			 double T/**< double. Total time of the considerated problem */,
			 double D/**< double. Diffusion coefficient of the material */,
			 double Tsur/**< double. The temperature that will be applied on the boundaries of the material */,
			 double Tin/**< double. The initial temperature of the material */ );
	/**
	 *  Compute the solution and return it. This method is the Crank-Nicolson method applied to the heat diffusion equation problem
	 *  @return Matrix. The computed matrix, can also be accesed through getComputedSolution()
	 *  @see getComputedSolution()
	 */
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
