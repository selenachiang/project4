#include "text-menu-app.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

TextMenuApp::TextMenuApp() {
	this->patients = Patients();
}

void TextMenuApp::run() {
	
	// MESSAGES TO DISPLAY TO USER
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
		" patients in total.\n\n",
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
		"Patient updated!\n\n",
		// 16
		"Input the file name to save the data to: ",
		// 17
		"File saved!\n\n",
		// 18
		"Save failed!\n\n",
		// 19
		"Invalid index, please input again!\n",
		// 20
		"Age is impossibly high or low!\n",
		// 21
		"Invalid input, Male or Female only!\n",
		//22
		"Thank you for using the app!\n"
	};

	// OPEN INPUT FILE TO INITIALIZE PATIENTS
	string inputFile;
	while (true) {
		cout << messages[0];
		cin >> inputFile;
		// CHECKS IF FILE WAS OPENED SUCCESSFULLY
		if (this->patients.load(inputFile)) {
			break;
		}
		cout << messages[1]; 
	}

	// RUNS CONTINUOUSLY UNTIL USER QUITS
	int userInput = 0;
	do {
		while (true) {	
			// PRINT MAIN MENU
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
		// SWITCH BASED ON VALID USER CHOICE FROM MAIN MENU OPTIONS
		switch (userInput) {
			// PRINT INFO OF ALL PATIENTS
			case 1: {
				this->patients.printAll();
				cout << this->patients.getCount() << messages[8];
				break;
			}
			// UPDATE THE INFO OF A PATIENT
			case 2: {
				int index = 0;
				string name;
				int age = 0;
				string gender;
				// GET PATIENT INDEX
				while (true) {
					cout << messages[9] << endl;
					cin >> index;
					// CHECK IF PATIENT INDEX IS VALID
					if (index >= 0 && index < this->patients.getCount()) {
						break;
					}
					cout << messages[19];
				}
				// GET NEW NAME (y'all got all kinds of crazy names so no validation)
				cout << messages[12];
				cin >> name;
				// GET NEW AGE
				while (true) {	
					cout << messages[13];
					cin >> age;
					// CHECK IF AGE IS TOO LOW OR HIGH
					if (age >= 0 && age <= 150) {
						break;
					}
					cout << messages[20];
				}
				// GET NEW GENDER
				while (true) {
					cout << messages[14];
					cin >> gender;
					// CHECK FOR VALID GENDER (sorry non-binary folks lol)
					for (long unsigned int i = 0; i < gender.length(); i++) {
						gender[i] = toupper(gender[i]);
					}
					if (gender == "M" || gender == "MALE") {
						gender = "Male";
						break;
					}
					if (gender == "F" || gender == "FEMALE") {
                                                gender = "Female";
                                                break;
                                        }
					cout << messages[21];
				}
				// UPDATE PATIENT BASED ON PROVIDED INFO
				this->patients.updatePatient(index, name, age, gender);
				cout << messages[15];
				break;
			}
			// SAVE FILE
			case 3: {
				while (true) {
					string outputFile;
					cout << messages[16];
					cin >> outputFile;
					// CHECK IF SAVE SUCCESSFUL
					if (this->patients.save(outputFile)) {
						cout << messages[17];
						break;
					}
					cout << messages[18];
				}
				break;
			}
			default: {
				break;
			}
		}
	}
	while (userInput != 4);
	// USER QUIT
	cout << messages[22];
}
