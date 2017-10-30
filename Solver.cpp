#include "Solver.h"
#include <cmath>


Solver::Solver(double dx, double dt, double L, double T, double D, double Tsur, double Tin){
	(*this).dx = dx;
	(*this).dt = dt;
	(*this).L = L;
	(*this).T = T;
	(*this).D = D;
	(*this).Tsur = Tsur;
	(*this).Tin = Tin;
	int nRows = (T/dt)+1;//We also want the initialization time
	int nCols = (L/dx)+1;//We need the two boundaries
	Matrix m(nRows,nCols);
	(*this).computedSolution = m;
}

Matrix Solver::getComputedSolution() {

	return (*this).computedSolution;
}

double Solver::getDT(){
	return (*this).dt;
}

double Solver::getDX(){
	return (*this).dx;
}

double Solver::getL(){
	return (*this).L;
}

double Solver::getT(){
	return (*this).T;
}

std::ostream& operator<<(std::ostream& os, Solver& s) {

	Matrix m = s.getComputedSolution();

	if (m.getNrows() > 0) {
		os << "The matrix elements are" << std::endl;
		double T = 0.0;
		int i,t = 0;
		for(double T=0.0; T <= 0.5 ; T = T + 0.1){
			os << "T = " << T << " -> ";
			i = T/s.getDT();
			for (int j=0;j<m.getNcols();j++) {
				os << m[i][j]  << " ";
			}
			os << "\n";
		}
		os << std::endl;
	}else{
		os << "Matrix is empty." << std::endl;
	}
	return os;
}


std::ofstream& operator<<(std::ofstream& ofs, Solver& s) {

	Matrix m = s.getComputedSolution();
	int i,j =0;
	double x = 0.0;
	double L = s.getL();
	if (m.getNrows() > 0) {
		for(int k=0;k<=20;k++){
			x = k*0.05;
			ofs << x  << " ";
			for(double t = 0.0; t <= s.getT(); t += 0.1){
				std::cout << t << std::endl;
				i = t/s.getDT();
				j = x/s.getDX();
				ofs << m[i][j]  << " ";

			}
			ofs << std::endl;
			x += 0.05;
		}
	}

	return ofs;
}
