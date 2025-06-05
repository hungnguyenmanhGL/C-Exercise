#include "Experience.h"

Experience::Experience() : Employee() {}

Experience::Experience(string id, string fullName, Date birthday, string phone, string email, EmployeeType type,
	int expYear, string proSkill)
	: Employee(id, fullName, birthday, phone, email, type) {
	this->expYear = expYear;
	this->proSkill = proSkill;
}

Experience::~Experience() {}

void Experience::ShowInfo() {
	Employee::ShowInfo();
	printf("Experience-specific:\n"
		" Experience year: %d\n"
		" Professional skill: %s\n",
		expYear, proSkill.c_str());
}