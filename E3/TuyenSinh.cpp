#include "TuyenSinh.h"
#include <iostream>
using namespace std;

void TuyenSinh::ShowInfo() {
	for (shared_ptr<Student>& s : studentList) {
		s->ShowInfo();
	}
	cout << "End Of List" << endl;
}

void TuyenSinh::AddStudent(shared_ptr<Student> student) {
	studentList.push_back(student);
}

shared_ptr<Student> TuyenSinh::GetById(const string& id) {
	for (shared_ptr<Student>& s : studentList) {
		if (s->GetId()._Equal(id)) {
			return s;
		}
	}
	printf("Id %s not found.\n", id.c_str());
	return nullptr;
}

TuyenSinh::TuyenSinh() {}

TuyenSinh::~TuyenSinh() {}