#include "text-menu-app.hpp"
#include <iostream>
#include <string>
#include <vector>


using namespace std;

TextMenuApp::TextMenuApp() {
	this->patients = Patients();
}

void TextMenuApp::run() {
	
	vector<string> messages = {
		"Input the file name to load initial data from: ",
		"File cannot be opened! Input again!\n",
		"1. Print all patients;\n",
		"2. Update information of a patient;\n",
		"2. Update information of a patient;\n",
		"4. Exit.\n",
		"Please choose an option(1-4): ",
		"The choice should be between 1 and 4!\n",
		" patients in total.\n \n"
	};

	// OPEN INPUT FILE TO INITIALIZE PATIENTS
	string inputFile;
	while (true) {
		cout << messages[0];
		cin >> inputFile;
		if (this->patients.load(inputFile)) {
			break;
		}
		cout << messages[1]; 
	}

	int userInput = 0;
	do {
		while (true) {	
			// PRINT MENU
			for (int i = 2; i < 7; i++) {
				cout << messages[i];
			}
			cin >> userInput;

			// VALIDATE MENU CHOICE
			if (userInput >= 1 && userInput <= 4) {
				break;
			}
			cout << messages[7];
		}
		switch (userInput) {
			case 1:
				this->patients.printAll();
				cout << this->patients.getCount() << messages[8];
				break;
			default:
				break;
		}
	}
	while (userInput != 4);
}
