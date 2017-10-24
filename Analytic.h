#pragma once
#include "Solver.h"
class Analytic :public Solver {
public:
	Analytic();
	Analytic(int nRows, int nCols);
	Matrix virtual computeSolution(double dt, double dx, double D, double Tsur, double Tin);
	~Analytic(){}
};
