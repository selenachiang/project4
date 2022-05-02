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

	if (read.is_open()) {
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

bool Patients::save(const std::string &filename) {
	ofstream write;
	write.open(filename);
	if (write.is_open()) {
		write << to_string(this->count) << "\n";
		
		for (int i = 0; i < this->count; i++) {
			write << this->patients[i].getName() << ", ";
			write << this->patients[i].getAge() << ", ";
			write << this->patients[i].getGender() << "\n";
		}
		write << "\n";

		// CLOSE OUTPUT FILE
		write.close();
		return true;
	}
	return false;
}

void Patients::updatePatient(int id, const std::string &name, int age, std::string gender) {
	this->patients[id] = Patient(name, age, gender);
}

std::string Patients::getPatientInfo(int id) const {
	return this->patients[id].info();
}

const int Patients::getCount() const {
	return this->count;
}

void Patients::printAll() const {
	for (int i = 0; i < this->count; i++) {
		cout << i << ": " << this->patients[i].info() << endl;
	}
}
