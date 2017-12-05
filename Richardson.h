#ifndef RICHARDON_H_  //include guard
#define RICHARDON_H_

/*
 * Richardson.h
 *
 *  Created on: 25 oct. 2017
 *      Author: yoann
 *
 *   This class inherits from Solver and provide an approximated solution of the heat diffusion equation using Richardson's explicit scheme
 */



#include "Solver.h"

class Richardson: public Solver {
public:

	//CONSTRUCTOR
	/**
	 * Construcs a solver of the problem using Richardson method
	 */
	Richardson(double dx/**< double. distance between two space steps */,
			 double dt/**< double. time between two time steps */,
			 double L/**< double. width of the 1D material to consider */,
			 double T/**< double. Total time of the considerated problem */,
			 double D/**< double. Diffusion coefficient of the material */,
			 double Tsur/**< double. The temperature that will be applied on the boundaries of the material */,
			 double Tin/**< double. The initial temperature of the material */ );
	/**
	 *  Compute the solution and return it. This method is the Richardson method applied to the heat diffusion equation problem
	 *  @return Matrix. The computed matrix, can also be accesed through getComputedSolution()
	 *  @see getComputedSolution()
	 */
	Matrix virtual computeSolution();
	virtual ~Richardson();
};

#endif

