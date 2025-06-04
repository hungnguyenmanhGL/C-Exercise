#include "Admission.h"
#include <iostream>
using namespace std;

void Admission::ShowInfo() {
	for (shared_ptr<Student>& s : studentList) {
		s->ShowInfo();
	}
	cout << "End Of List" << endl;
}

void Admission::AddStudent(shared_ptr<Student> student) {
	studentList.push_back(student);
}

shared_ptr<Student> Admission::GetById(const string& id) {
	for (shared_ptr<Student>& s : studentList) {
		if (s->GetId()._Equal(id)) {
			return s;
		}
	}
	printf("Id %s not found.\n", id.c_str());
	return nullptr;
}

Admission::Admission() {}

Admission::~Admission() {}