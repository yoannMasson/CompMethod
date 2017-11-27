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


	cout << fixed;
	cout << setprecision(2);
	char choice('0');
	while (choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5'){
		cout << "Please chose the method to compute the problem: " << endl << "1. Dufort-Frankel" << endl << "2. Richardson" << endl << "3. Laasonen" << endl << "4. Crank-Nicholson" << endl << "5. Analytic solution" << endl;
		cin >> choice;

	}

	switch (choice) {
	case '1':{
		DufortFrankel dufortFrankel(DX,DT,THICNESS,T,D,TSUR,TIN);
		cout << dufortFrankel.computeSolution();
		cout << dufortFrankel;

		ofstream f;
		f << fixed;
		f << setprecision(2);
		f.open ("Dufort Frankel");
		f << dufortFrankel;
		f.close();
	}
	break;
	case '2':{
		Richardson richardson(DX,DT,THICNESS,T,D,TSUR,TIN);
		cout << richardson.computeSolution();
		cout << richardson;

		ofstream f;
		f << fixed;
		f << setprecision(2);
		f.open ("Richardson");
		f << richardson;
		f.close();

	}
	break;
	case '3':{
		Laasonen laasonen(DX,DT,THICNESS,T,D,TSUR,TIN);
		cout << laasonen.computeSolution();
		cout << laasonen;

		ofstream f;
		f << fixed;
		f << setprecision(2);
		f.open ("Laasonen");
		f << laasonen;
		f.close();
	}
	break;
	case '4':{
		CrankNicolson crankNicholson(DX,DT,THICNESS,T,D,TSUR,TIN);
		crankNicholson.computeSolution();
		cout << crankNicholson;

		Analytic analytic(DX,DT,THICNESS,T,D,TSUR,TIN);
		analytic.computeSolution();

		//cout << crankNicholson.getComputedSolution() - analytic.getComputedSolution();
		ofstream f;
		f << fixed;
		f << setprecision(2);
		f.open ("CrankNicolson");
		f << crankNicholson;
		f.close();
	}
	break;
	case '5':
	{
		Analytic analytic(DX,DT,THICNESS,T,D,TSUR,TIN);
		analytic.computeSolution();
		cout << analytic.getComputedSolution();
		cout << analytic;

		ofstream f;
		f << fixed;
		f << setprecision(2);
		f.open ("Analytic");
		f << analytic;
		f.close();

	}
	break;

	}
	return 0;
}

