#include <iostream>
#include "Analytic.h"
#include <cstdlib>

using namespace std;
int main() {

	char choice('0');
	while (choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5'){
		cout << "Please chose the method to compute the problem: " << endl << "1. Dufort-Frankel" << endl << "2. Richardson" << endl << "3. Laasonen" << endl << "4. Crank-Nicholson" << endl << "5. Analytic solution" << endl;
		cin >> choice;
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
		Analytic analytic;
		cout << "ere";
		cout << analytic.computeSolution(0.05,0.1,0.1,300.0,100.0);
		cout << "lol ";
		break;
	}
	system("pause");
	return 0;
}
