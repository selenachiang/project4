#include "patients.hpp"
#include <iostream>
#include <fstream>

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

	if (read.is_open) {
		string patientCount;
		getline(read, patientCount);
		this->count = stoi(patientCount);

		this->patients = new Patient[this->count];

		for (int i = 0; i < this->count; i++) {
			string line;
			getline(read,line);
			this->patients[i] = Patient(line);
		}
		read.close();
		return true;
	}
	return false;
}

//bool Patients::save(const std::string &filename);

//void Patients::updatePatient(int id, const std::string &name, int age, std::string gender);

//std::string Patients::getPatientInfo(int id) const;

const int Patients::getCount() const {
	return this->count;
}

void Patients::printAll() const {
	for (int i = 0; i < this->count; i++) {
		cout << this->patients[i].info() << endl;
	}
	cout << endl;
}
