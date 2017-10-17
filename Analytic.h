#pragma once
#include "Solver.h"
class Analytic :public Solver {
public:
	Analytic();
	virtual Matrix computeSolution(double dt, double dx, double D, double Tsur, double Tin);
};

