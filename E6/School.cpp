#include "School.h"
using namespace std;

void School::AddStudent(Student& student) {
	studentList.push_back(student);
}

School::School() {}

School::~School() {}

void School::ShowAge20() {
	for (Student& s : studentList) {
		if (s.GetAge() == 20) {
			s.ShowInfo();
		}
	} cout << "End Of List" << endl;
}

void School::ShowAge23DaNang() {
	for (Student& s : studentList) {
		if (s.GetAge() == 23 && s.GetBirthplace()._Equal("DN")) {
			s.ShowInfo();
		}
	} cout << "End Of List" << endl;
}

void School::InputAdd() {
	string name;
	cout << "Name: ";
	getline(cin, name);

	int age;
	do {
		cout << "Age: ";
		cin >> age;
		cin.ignore();
		if (age <= 0) cout << "Invalid age. Try again" << endl;
	} while (age <= 0);

	string birthplace;
	cout << "Birthplace: ";
	getline(cin, birthplace);

	string className;
	cout << "Class: ";
	getline(cin, className);

	Student student{ name, age, birthplace, className };
	AddStudent(student);
}
