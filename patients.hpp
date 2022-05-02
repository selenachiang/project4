#ifndef PATIENTS_HPP
#define PATIENTS_HPP

#include "patient.hpp"

#include <string>

class Patients {

	private:

		Patient *patients;

		int count;

	public:

		Patients();

		~Patients();

		bool load(const std::string &filename);

		bool save(const std::string &filename);

		void updatePatient(int id, const std::string &name, int age, std::string gender);

		std::string getPatientInfo(int id) const;

		const int getCount() const;

		void printAll() const;

};

#endif 
