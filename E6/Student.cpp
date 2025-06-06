#include "Student.h"
#include <stdio.h>

void Student::ShowInfo() {
	printf("Name: %s\n Age: %d\n Birthplace: %s\n Class: %s\n",
		name.c_str(), age, birthplace.c_str(), className.c_str());
}

Student::Student(string name, int age, string birthplace, string className)
	: name(name), age(age), birthplace(birthplace), className(className) {
}

Student::Student() {}

Student::~Student() {}

void Student::SetName(string name) { this->name = name; }

void Student::SetAge(int age) { this->age = age; }

void Student::SetBirthplace(string birthplace) { this->birthplace = birthplace; }

void Student::SetClass(string className) { this->className = className; }

int Student::GetAge() { return this->age; }

string Student::GetBirthplace() { return this->birthplace; }
