#include "text-menu-app.hpp"
#include <iostream>

using namespace std;

TextMenuApp::TextMenuApp() {
	this->patients = new Patients();
}

void TextMenuApp::run() {
	cout << "HELLO WORLD" << endl;
}
