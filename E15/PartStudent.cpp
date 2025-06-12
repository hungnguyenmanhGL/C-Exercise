#include "PartStudent.h"

PartStudent::PartStudent() { 
	this->isFullTime = false; 
}

PartStudent::PartStudent(string id, string name, Date dob, int enrollYear, int entryScore, vector<StudyResult>& resList, string city)
	: Student(id, name, dob, enrollYear, entryScore, resList), city(city) {
	this->isFullTime = false;
}

void PartStudent::ShowInfo() {
	Student::ShowInfo();
	printf(" City: %s\n", city.c_str());
}