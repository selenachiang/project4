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
		
		//TODO
		Patient(const std::string &text);
		
		Patient(const std::string &name, int age, std::string gender);
		
		const std::string getName() const;

		//TODO
		const int getAge() const;

		const std::string getGender() const;

		//TODO 
		std::string info() const;
};

#endif
