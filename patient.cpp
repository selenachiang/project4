#include "patient.hpp"
#include <iostream>
#include <sstream>

using namespace std;

Patient::Patient() {
	this->age = 0;
}

Patient::Patient(const std::string &text) {
	std::string name;
	std::string age;
	std::string gender;
	
	// CREATE STRINGSTREAM FROM FUNCTION PARAMETER
	stringstream sstream(text);

	getline(sstream, name, ',');
	sstream.ignore(1);
	getline(sstream, age,  ',');
	sstream.ignore(1);
	getline(sstream, gender);

	this->name = name;
	this->age = stoi(age);
	this->gender = gender;
}

Patient::Patient(const string &name, int age, string gender) {
	this->name = name;
	this->age = age;
	this->gender = gender;
}

const string Patient::getName() const {
	return this->name;
}

const int Patient::getAge() const {
	return this->age;
}

const std::string Patient::getGender() const {
	return this->gender;
}

std::string Patient::info() const {
	return "Name: " + this->name + " | Age: " + to_string(this->age) + " | Gender: " + this->gender;

}
