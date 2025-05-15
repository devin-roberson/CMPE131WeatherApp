#include <iostream>
#include "weather.h"
using namespace std;

int main() {
	bool run = true;
	int choice;
	weatherStation x;
	while (run)
	{
		cout << "Welcomme to the weather station program!\nEnter the following digits for options:\n1: getData()\n2: analyze\n3: save\n4: transmit\n5: Exit\nInput: ";
		cin >> choice;
		system("cls");
		switch (choice) {
		case 1:
			x.getData();
			break;
		case 2:
			x.analyzeData();
			break;
		case 3:
			x.storeData();
			break;
		case 4:
			x.transmitData();
			break;
		case 5:
			run = false;
			break;
		default:
			cout << "Bad input!" << endl;
			break;
		}
	}
	cout << "Thank you for using this program.";
}