//#include "text-menu-app.hpp"

#include "patients.hpp"
//remove
#include <iostream>

int main() {
	//TextMenuApp menu;
	//menu.run();

	std::string patient = "Alan Harry, 24, Male";
	Patient p(patient);

	std::cout << p.info() << std::endl;
	std::cout << p.getName() << std::endl;
	std::cout << p.getAge() << std::endl;
	std::cout << p.getGender() << std::endl;

	Patients ps = new Patients();
	//ps.load("patients.txt");
	//std::cout << ps.getCount() << std::endl;

	return EXIT_SUCCESS;
}
