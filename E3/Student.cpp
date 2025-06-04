#include "Student.h"
#include <stdio.h>

void Student::ShowInfo() {
	printf("ID: %s\n Name: %s\n Address: %s\n Priority: %d\n",
		id.c_str(), name.c_str(), address.c_str(), priority);
}


Student::Student(string id, string name, string address, int priority)
	: id(id), name(name), address(address), priority(priority) {
}

string Student::GetId() {
	return this->id;
}

Student::Student() {}

Student::~Student() {}
