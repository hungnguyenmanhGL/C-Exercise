#include <string>
#include <memory>
#include "Manager.h"
#include "Worker.h"
#include "Engineer.h"
#include "Staff.h"
#include <unordered_map>
using namespace std;

static enum OfficerType
{
	WORKER, ENGINEER, STAFF
};

static enum Command {
	ADD = 0,
	SHOW = 1,
	SEARCH = 2,
	QUIT = -1
};

Manager manager;

void InputAdd(int type) {
	cout << "First name: ";
	string firstName;
	cin.ignore(); //ignore "\n" at the end of previous cin
	getline(cin, firstName);
	

	cout << "Last name: ";
	string lastName;
	getline(cin, lastName);

	int age;
	do {
		cout << "Age: ";
		cin >> age;
		if (age <= 0) cout << "Invalid age. Try again." << endl;
	} while (age <= 0); 

	int gender;
	do {
		cout << "Gender (0 = Male, 1 = Female, 2 = Other): ";
		cin >> gender;
		if (gender < MALE || gender > OTHER) cout << "Invalid gender. Try again." << endl;
	} while (gender < MALE || gender > OTHER);

	cout << "Address: ";
	string address;
	cin.ignore();
	getline(cin, address);

	if (type == WORKER) {
		int level;
		do {
			cout << "Worker level: ";
			cin >> level;
			if (!Worker::IsLevelValid(level)) cout << "Invalid. Level must be from 1 to 10." << endl;
		} while (!Worker::IsLevelValid(level));

		manager.AddEmployee(shared_ptr<Officer>(new Worker(firstName, lastName, age, (Gender)gender, address, level)));
		cout << "Added new Worker." << endl;
	}
	else if (type == ENGINEER) {
		string major;
		cout << "Major: ";
		cin.ignore();
		getline(cin, major);
		manager.AddEmployee(shared_ptr<Officer>(new Engineer(firstName, lastName, age, (Gender)gender, address, major)));
		cout << "Added new Engineer" << endl;
	}
	else if (type == STAFF) {
		string position;
		cout << "Position: ";
		cin.ignore();
		getline(cin, position);
		manager.AddEmployee(shared_ptr<Officer>(new Staff(firstName, lastName, age, (Gender)gender, address, position)));
		cout << "Added new Staff" << endl;
	}
	
}

void InputSearch(const string lastName) {
	vector<shared_ptr<Officer>> res = manager.GetEmployeeByName(lastName);
	cout << res.size() << " results found." << endl;
	for (shared_ptr<Officer> match : res) {
		match->ShowInfo();
	}
}

void Input() {
	while (true) {
		cout << "Input command (0 = add/1 = show/2 = search/ -1 = quit): ";
		int cmd = -1;
		cin >> cmd;
		switch (cmd) {
		case ADD:
		{
			int type;
			do {
				cout << "Input officer type (0 = Worker, 1 = Engineer, 2 = Staff, -1 to quit): ";
				cin >> type;
				if (type == QUIT) {
					cout << "Quit adding." << endl;
					break;
				}

				if (type < WORKER || type > STAFF) {
					cout << "Invalid officer type. Try again." << endl;
				}
			} while (type < WORKER || type > STAFF);

			if (type == QUIT) break;

			InputAdd(type);
			break;
		}

		case SHOW:
		{
			manager.ShowInfo();
			break;
		}

		case SEARCH:
		{
			cout << "Last name to search: ";
			string lastName;
			cin.ignore();
			getline(cin, lastName);
			InputSearch(lastName);
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


