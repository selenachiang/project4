#ifndef PATIENT_HPP
#define PATIENT_HPP

#include <string>

class Patient
{
	
	private:
		
		std::string name;
		
		int age;
		
		std::string gender;
	
	public:
		
		Patient();
		
		Patient(const std::string &text);
		
		Patient(const std::string &name, int age, std::string gender);
		
		const std::string getName() const;

		const int getAge() const;

		const std::string getGender() const;

		std::string info() const;
};

#endif
