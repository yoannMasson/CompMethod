#include <iostream>
#include "Analytic.h"
#include <cstdlib>

using namespace std;

void static pauseTheSystem();

const double THICNESS = 1.0;
const double TIN = 100.0;
const double TSUR = 300.0;
const double D = 0.1;
const double DX = 0.05;
const double DT = 0.1;

int main() {

	char choice('0');
	while (choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5'){
		cout << "Please chose the method to compute the problem: " << endl << "1. Dufort-Frankel" << endl << "2. Richardson" << endl << "3. Laasonen" << endl << "4. Crank-Nicholson" << endl << "5. Analytic solution" << endl;
		//cin >> choice;
		choice = '5';
	}

	switch (choice) {
	case '1':
		break;
	case '2':
		break;
	case '3':
		break;
	case '4':
		break;
	case '5':
		double nRows = 20/DT;
		double nCols = THICNESS / DX;
		Analytic analytic(nRows,nCols);
		cout << analytic.computeSolution(DT,DX,D,TSUR,TIN);
		break;
	}
	pauseTheSystem();
	return 0;
}

void static pauseTheSystem(){

	cout << "End of the programm, press any key to continue..." << endl;
	string s("");
	cin >> s;

}
