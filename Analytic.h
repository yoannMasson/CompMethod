

#ifndef ANALYTIC_H_
#define ANALYTIC_H_

/*
 * CrankNicholson.h
 *
 *  Created on: 25 oct. 2017
 *      Author: yoann
 *
 *	This class inherits from Solver and provide the analytical solution of the heat diffusion equation
 */

#pragma once
#include "Solver.h"

class Analytic :public Solver {
public:
	//CONSTRUCTOR
	/**
	 * Construcs an analyic object
	 */
	Analytic(double dx/**< double. distance between two space steps */,
			 double dt/**< double. time between two time steps */,
			 double L/**< double. width of the 1D material to consider */,
			 double T/**< double. Total time of the considerated problem */,
			 double D/**< double. Diffusion coefficient of the material */,
			 double Tsur/**< double. The temperature that will be applied on the boundaries of the material */,
			 double Tin/**< double. The initial temperature of the material */ );

	/**
	 *  Compute the solution and return it. This method is the analytical solution of the heat diffusion equation problem
	 *  @return Matrix. The computed matrix, can also be accesed through getComputedSolution()
	 *  @see getComputedSolution()
	 */
	Matrix virtual computeSolution();

	~Analytic(){}
};

#endif //ANALYTIC_H_
