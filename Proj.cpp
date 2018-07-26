#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;

double xI, xI_1, h_XI, h_XI_1, t, eS, eA; //First guessed value
int amtIteration;
bool go = true;

double height(double x) {
	return (pow(x,3.0))-(7*(pow(x,2.0)))-(pow(31,-3));	
}



int main() {
	int count = 0;

	cout << "Enter you two guesses" << endl;
	cout << "Guess 1: ";
	cin >> xI;
	cout << "Guess 2: ";
	cin >> xI_1;

	cout << endl << "Enter the amount of iterations to be performed: ";
	cin >> amtIteration;

	cout << endl << "Enter your pre-specified relative error of tolerance: ";
	cin >> eS;

	while(go){
		h_XI = height(xI);
		h_XI_1 = height(xI_1);

		t = xI;

		xI = xI - ((h_XI * (xI - xI_1)) / (h_XI - h_XI_1));
		
		xI_1 = t;

		eA = abs((xI - xI_1) / xI) * 100;

		count++;

		cout << "Estimated root (gas oil on a dipstick): " << xI << endl;
		cout << "Approximate error: " << eA << endl << endl;

		if ((count < amtIteration) || (eA > eS)) 
			go = true;
		else {
			go = false;
			cout << "Terminate" << endl;
		}
	}

	system("pause");
	return 0;
}