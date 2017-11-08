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
	Vector bottomDiagonal((L/dx)-1);//The upper diagonal of the triangle matrix A of the system A.F = D
	Vector upDiagonal((L/dx)-1);//The upper diagonal of the triangle matrix A of the system A.F = D
	Vector diagonal(L/dx);//The main diagonal of the triangle matrix A of the system A.F = D
	Vector resultVector(L/dx);//The D vector of the system A.F = D;
	Vector f(L/dx);//The f vector of the previus iteration
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

	for(int i = 0; i< L/dx ; i++){
		diagonal[i] = 1+2*C;
	}

	for(int i = 0; i< L/dx-1 ; i++){
		upDiagonal[i] = -C;
		bottomDiagonal[i] = -C;
	}
	//f is the fist time step at initialization
	for(int j = 0 ; j < nCols; j++){
		f[j] = m[0][j];
	}

	//Filling resultVector with init values
	f[0] = 300;
	f[L/dx-1] = 300;
	for(int i = 1 ; i < (L/dx)-1 ; i++){
		resultVector[i] = C*f[i+1]+(1-2*C)*f[i]+C*f[i-1];
	}
	resultVector[0] = Tsur;
	resultVector[L/dx -1] = Tsur;
	std::cout << resolveOneStep(bottomDiagonal,diagonal,upDiagonal,resultVector,f);
	//Calcul
	for (int timeStep = 0; timeStep < nRows-1; timeStep++) {
		f = resolveOneStep(bottomDiagonal,diagonal,upDiagonal,resultVector,f);
		cout << f;
	}
	(*this).computedSolution = m;
	return m;
}

Vector CrankNicholson::resolveOneStep(Vector bottomDiagonal,
		Vector diagonal,
		Vector upDiagonal,
		Vector resultDiagonal,
		Vector &f){
	//Initialization
	Vector tempUp((L/dx)-1);
	Vector tempRes((L/dx));


	tempUp[0] = upDiagonal[0]/diagonal[0];
	tempRes[0] = Tsur;

	tempRes[(L/dx)-1] = resultDiagonal[(L/dx)-1];
	for(int i= 1 ; i < (L/dx-1) ; i++){
		tempUp[i] = upDiagonal[i]/(diagonal[i]-bottomDiagonal[i]*tempUp[i-1]);
		tempRes[i] = (resultDiagonal[i]-bottomDiagonal[i]*tempRes[i-1])/(diagonal[i]-bottomDiagonal[i]*tempUp[i-1]);
	}
	tempRes[(L/dx)-1] = resultDiagonal[(L/dx)-1];
/*	cout << "result Diagonal" << resultDiagonal;
	cout << "f diagonal" << f;
	cout << "top diagonal" << upDiagonal;
	cout << "bottom diagonal" << bottomDiagonal;
	cout << "Diagonal" << diagonal;
	cout << "tempUp: " << tempUp;
	cout << "tempRes: " << tempRes;*/
	//reverse resolving the system
	f[(L/dx-1)] = tempRes[(L/dx-1)];
	for(int i = (L/dx)-2;i > 0;i--){
		f[i] = tempRes[i]-tempUp[i]*f[i+1];
	}

	return f;

}

CrankNicholson::~CrankNicholson() {
	// TODO Auto-generated destructor stub
}

