#include "Solver.h"


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
