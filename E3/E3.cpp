#include <iostream>
#include "Admission.h"
using namespace std;

static enum Command {
	ADD = 0,
	SHOW = 1,
	SEARCH = 2,
	QUIT = -1
};

Admission ad;

void InputAdd() {
	cout << "Id: ";
	string id;
	cin.ignore();
	getline(cin, id);

	cout << "Name: ";
	string lastName;
	getline(cin, lastName);

	int age;
	do {
		cout << "Age: ";
		cin >> age;
		if (age <= 0) cout << "Invalid age. Try again." << endl;
	} while (age <= 0);

	cout << "Address: ";
	string address;
	cin.ignore();
	getline(cin, address);

	int priority;
	cout << "Priority: ";
	cin >> priority;

	char block;
	do {
		cout << "Block (valid block is A/B/C): ";
		cin >> block;
		if (!Student::IsValidBlock(block)) cout << "Invalid block." << endl;
	} while (!Student::IsValidBlock(block));

	ad.AddStudent(shared_ptr<Student>(new Student(id, lastName, address, priority, block)));
	cout << "Added new student." << endl;
}

void InputSearch(const string id) {
	shared_ptr<Student> res = ad.GetById(id);
	if (res == nullptr) {
		cout << "0 match found for id " << id << endl;
		return;
	}
	res->ShowInfo();
}

void Input() {
	while (true) {
		cout << "Input command (0 = add/1 = show/2 = search/ -1 = quit): ";
		int cmd = -1;
		cin >> cmd;
		switch (cmd) {
		case ADD:
		{
			InputAdd();
			break;
		}

		case SHOW:
		{
			ad.ShowInfo();
			break;
		}

		case SEARCH:
		{
			cout << "Id to search: ";
			string id;
			cin.ignore();
			getline(cin, id);
			InputSearch(id);
			break;
		}

		case QUIT:
		{
			cout << "Quitting..." << endl;
			break;
		}

		default:
		{
			cout << "Invalid command. Try again." << endl;
			break;
		}
		}

		if (cmd == QUIT) break;
	}
}

int main()
{
	Input();
}