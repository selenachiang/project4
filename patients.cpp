#include "patients.hpp"
#include <iostream>

using namespace std;

Patients::Patients() {
	this->patients = nullptr;
	this->count = 0;
}

Patients::~Patients() {
	delete [] patients;
}

bool Patients::load(const std::string &filename) {
	// READ CONTENTS OF FILE AND CREATE DYNAMIC ARRAY OF PATIENT OBJECTS
	ifstream read;
	read.open(filename);

	this->count = stoi(getline(read));	

	//string patient;
	//while (read) {
	//	getline(read, patient);
		
	read.close();
}

//bool Patients::save(const std::string &filename);

//void Patients::updatePatient(int id, const std::string &name, int age, std::string gender);

//std::string Patients::getPatientInfo(int id) const;

int Patients::getCount() const {
	return this->count;
}

void Patients::printAll() const {
	for (int i = 0; i < count; i++) {
		cout << this->patients[i]->info() << endl;
	}
	cout << endl;
}
