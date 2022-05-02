#include "text-menu-app.hpp"

//#include "patients.hpp"
//remove
#include <iostream>

int main() {
	TextMenuApp menu;
	menu.run();

	std::string patient = "Alan Harry, 24, Male";
	Patient p(patient);

	std::cout << p.info() << std::endl;
	std::cout << p.getName() << std::endl;
	std::cout << p.getAge() << std::endl;
	std::cout << p.getGender() << std::endl;


	std::string filename = "patients.txt";

	Patients ps;
	ps.load(filename);
	ps.printAll();

	std::string output = "output.txt";
	ps.save(output);

	ps.updatePatient(1, "Bob", 100, "Female");
	std::cout << ps.getPatientInfo(1);

	return EXIT_SUCCESS;
}
