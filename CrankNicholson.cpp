/*
 * CrankNicholson.cpp
 *
 *  Created on: 31 oct. 2017
 *      Author: yoann
 */

#include "CrankNicholson.h"
#include "vector.h";

using namespace std;

CrankNicholson::CrankNicholson(double dx, double dt, double L, double T, double D, double Tsur, double Tin ):
				Solver (dx, dt, L, T, D, Tsur, Tin){}

Matrix CrankNicholson::computeSolution(){

	Matrix m = getComputedSolution();//Matrix containing the result
	int nRows = m.getNrows();
	int nCols = m.getNcols();
	Vector bottomDiagonal(nCols);//The upper diagonal of the triangle matrix A of the system A.F = D
	Vector upDiagonal(nCols);//The upper diagonal of the triangle matrix A of the system A.F = D
	Vector diagonal(nCols);//The main diagonal of the triangle matrix A of the system A.F = D
	Vector resultVector(nCols);//The D vector of the system A.F = D;
	Vector f(nCols);//The f vector of the previus iteration
	double const C = D*dt/(2*dx*dx);

	//initialisation
	for (int i = 0; i < nRows; i++) {
		for (int j = 0; j < nCols ; j++) {
			if(j == 0 || j == nCols-1){
				m[i][j] = 300;
			}else{
				m[i][j] = 100;
			}
		}
	}

	for(int i = 0; i< nCols ; i++){
		diagonal[i] = 1+2*C;
	}

	for(int i = 0; i< nCols ; i++){
		upDiagonal[i] = -C;
		bottomDiagonal[i] = -C;
	}
	bottomDiagonal[0] = 0;
	upDiagonal[nCols-1] = 0;
	//f is the fist time step at initialization
	for(int j = 0 ; j < nCols; j++){
		f[j] = m[0][j];
	}

	//Filling resultVector with init values
	f[0] = 300;
	f[nCols-1] = 300;
	for(int i = 1 ; i < nCols-1 ; i++){
		resultVector[i] = C*f[i+1]+(1-2*C)*f[i]+C*f[i-1];
	}
	resultVector[0] =  C*f[1]+(1-2*C)*f[0]+C*Tsur;
	resultVector[nCols -1] =  C*Tsur+(1-2*C)*f[nCols -1]+C*f[nCols -2];
	std::cout << resolveOneStep(bottomDiagonal,diagonal,upDiagonal,resultVector,f);
	//Calcul
	/*for (int timeStep = 0; timeStep < nRows-1; timeStep++) {
		f = resolveOneStep(bottomDiagonal,diagonal,upDiagonal,resultVector,f);
		for(int i = 0; i < nCols ; i++){
			m[1][i] = f[i];
		}
	}*/

	(*this).computedSolution = m;
	return m;
}

Vector CrankNicholson::resolveOneStep(Vector bottomDiagonal,
		Vector diagonal,
		Vector upDiagonal,
		Vector resultDiagonal,
		Vector &f){
	//Initialization
	int nCols = this->getComputedSolution().getNcols();
	Vector tempUp(nCols-1);
	Vector tempRes(nCols);
	

	tempUp[0] = upDiagonal[0]/diagonal[0];


	for(int i= 1 ; i < nCols-1 ; i++){
		tempUp[i] = upDiagonal[i]/(diagonal[i]-bottomDiagonal[i]*tempUp[i-1]);
	}

	tempRes[0] = resultDiagonal[0]/diagonal[0];
	for(int i= 1 ; i < nCols ; i++){
		tempRes[i] = (resultDiagonal[i]-bottomDiagonal[i]*tempRes[i-1])/(diagonal[i]-bottomDiagonal[i]*tempUp[i-1]);
	}


	cout << "result Diagonal" << resultDiagonal;
	cout << "f diagonal" << f;
	cout << "top diagonal" << upDiagonal;
	cout << "bottom diagonal" << bottomDiagonal;
	cout << "Diagonal" << diagonal;
	cout << "tempUp: " << tempUp;
	cout << "tempRes: " << tempRes;
	//reverse resolving the system
	f[nCols-1] = tempRes[nCols-1];
	for(int i = nCols-2;i >= 0 ; i--){
		f[i] = tempRes[i]-tempUp[i]*f[i+1];
	}

	return f;

}

CrankNicholson::~CrankNicholson() {
	// TODO Auto-generated destructor stub
}

