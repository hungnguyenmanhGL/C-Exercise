#include "Admission.h"
#include "StudentA.h"
#include "StudentB.h"
#include "StudentC.h"
#include <iostream>
using namespace std;

Admission::Admission() {}

Admission::~Admission() {}

void Admission::ShowInfo() {
	for (shared_ptr<Student>& s : studentList) {
		s->ShowInfo();
	}
	cout << "End Of List" << endl;
}

void Admission::AddStudent(shared_ptr<Student> student) {
	studentList.push_back(student);
}

void Admission::AddStudentByInput() {
	cout << "Id: ";
	string id;
	getline(cin, id);

	cout << "Name: ";
	string lastName;
	getline(cin, lastName);

	int age;
	do {
		cout << "Age: ";
		cin >> age;
		cin.ignore();
		if (age <= 0) cout << "Invalid age. Try again." << endl;
	} while (age <= 0);

	cout << "Address: ";
	string address;
	getline(cin, address);

	int priority;
	cout << "Priority: ";
	cin >> priority;
	cin.ignore();

	int block;
	do {
		cout << "Block (0 = block A, 1 = block B, 2 = block C): ";
		cin >> block;
		cin.ignore();
		switch (block)
		{
		case A: {
			AddStudent(shared_ptr<Student>(new StudentA(id, lastName, address, priority)));
			cout << "Added new student, block " << blockA << endl;
			break;
		}
		case B: {
			AddStudent(shared_ptr<Student>(new StudentB(id, lastName, address, priority)));
			cout << "Added new student, block " << blockB << endl;
			break;
		}
		case C: {
			AddStudent(shared_ptr<Student>(new StudentA(id, lastName, address, priority)));
			cout << "Added new student, block " << blockC << endl;
			break;
		}
		default: {
			cout << "Invalid block. Try again." << endl;
			break;
		}
		}
	} while (block < A || block > C);
}

void Admission::SearchIdByInput() {
	cout << "Id to search: ";
	string id;
	getline(cin, id);

	shared_ptr<Student> res = Admission::GetById(id);
	if (res == nullptr) {
		cout << "0 match found for id " << id << endl;
		return;
	}
	res->ShowInfo();
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