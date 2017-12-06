#include <iostream>
#include "Analytic.h"
#include "Richardson.h"
#include "Laasonen.h"
#include "DufortFrankel.h"
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include "CrankNicolson.h"

using namespace std;

const double THICNESS = 1.0;
const double TIN = 100.0;
const double TSUR = 300.0;
const double T = 0.5;
const double D = 0.1;
const double DX = 0.05;
const double DT = 0.01;

int main() {

	char choice('0');
	double elapsed;

	clock_t start, end;
	ofstream f;

	Analytic analytic(DX,DT,THICNESS,T,D,TSUR,TIN);//Use to compute errors
	DufortFrankel dufortFrankel(DX,DT,THICNESS,T,D,TSUR,TIN);
	Laasonen laasonen(DX,DT,THICNESS,T,D,TSUR,TIN);
	Richardson richardson(DX,DT,THICNESS,T,D,TSUR,TIN);
	CrankNicolson crankNicholson(DX,DT,THICNESS,T,D,TSUR,TIN);

	f << fixed;
	f << setprecision(2);
	cout << fixed;
	cout << setprecision(2);

	while (choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5'){
		cout << "Please chose the method to compute the problem: " << endl << "1. Dufort-Frankel" << endl << "2. Richardson" << endl << "3. Laasonen" << endl << "4. Crank-Nicholson" << endl << "5. Analytic solution" << endl;
		cin >> choice;

	}

	Solver *solution;

	analytic.computeSolution();

	switch (choice) {

	case '1':
		solution = &dufortFrankel;
		f.open ("DufortFrankel");
		break;

	case '2':
		solution = &richardson;
		f.open ("Richardson");
		break;

	case '3':
		solution = &laasonen;
		f.open ("Laasonen");
		break;

	case '4':
		solution = &crankNicholson;
		f.open ("CrankNicholson");
		break;

	case '5':
		solution = &analytic;
		f.open ("Analytic");
		break;
	}

	start = clock();
	solution->computeSolution();
	end = clock();
	elapsed = ((double)end - start) / CLOCKS_PER_SEC;
	elapsed *= 1000;//We want to print ms

	cout << *solution;

	Matrix error = solution->getComputedSolution()-analytic.getComputedSolution();
	cout << "it took "<< elapsed << " ms to compute" << endl;
	cout << "ERRORS: "<< endl;
	cout << "one norm: "<< error.one_norm()<< endl;
	cout << "second norm: "<< error.two_norm()<< endl;
	cout << "uniform norm: "<< error.uniform_norm()<< endl;



	f << *solution;
	f.close();
	return 0;
}

