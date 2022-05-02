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
		// 0
		"Input the file name to load initial data from: ",
		// 1
		"File cannot be opened! Input again!\n",
		// 2
		"1. Print all patients;\n",
		// 3
		"2. Update information of a patient;\n",
		// 4
		"3. Save file;\n",
		// 5
		"4. Exit.\n",
		// 6
		"Please choose an option(1-4): ",
		// 7
		"The choice should be between 1 and 4!\n",
		// 8
		" patients in total.\n \n",
		// 9
		"Please input patient's id as shown in the list: ",
		// 10
		"Invalid index, please input again!\n",
		// 11
		"The existing info:\n",
		// 12
		"Please input patient's new name: ",
		// 13
		"Please input patient's new age: ",
		// 14
		"Please input patients's new gender(Male/Female): ",
		// 15
		"Patient updated!\n"
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
			case 1: {
				this->patients.printAll();
				cout << this->patients.getCount() << messages[8];
				break;
			}
			case 2: {
				int index = 0;
				string name;
				int age;
				string gender;
				cout << messages[9] << endl;
				cin >> index;
				cout << messages[12];
				cin >> name;
				cout << messages[13];
				cin >> age;
				cout << messages[14];
				cin >> gender;
				this->patients.updatePatient(index, name, age, gender);
				cout << messages[15];
				break;
			}
			default: {
				break;
			}
		}
	}
	while (userInput != 4);
}
