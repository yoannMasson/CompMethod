#pragma once
#include "Solver.h"
class Analytic :public Solver {
public:
	Analytic(double dx, double dt, double L, double T, double D, double Tsur, double Tin );
	Matrix virtual computeSolution();
	~Analytic(){}
};
