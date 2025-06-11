#include "Student.h"

Student::Student(string name, Date doB, Gender gender, string phone, string uni, int gradeLvl)
	: fullName(name), doB(doB), gender(gender), phone(phone), university(uni), gradeLevel(gradeLvl) {
	this->isGood = false;
}

void Student::ShowInfo() {
	printf("Full name: %s\n"
		" Date of birth: %s\n"
		" Gender: %s\n"
		" Phone: %s\n"
		" University: %s\n"
		" Grade level: %d\n",
		fullName.c_str(), doB.ToString().c_str(), genderMap.at(gender).c_str(), phone.c_str(), university.c_str(), gradeLevel);
}

void Student::ShowContactData() {
	printf("Full name: %s\n"
		" Phone: %s\n",
		fullName.c_str(), phone.c_str());
}