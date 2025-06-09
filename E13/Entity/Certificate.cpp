#include "Certificate.h"
#include <stdio.h>
#include <iostream>
#include "Helper.h"

Certificate::Certificate(string id, string name, string rank, Date date)
	: id(id), name(name), rank(rank), date(date) { }

void Certificate::ShowInfo() {
	printf(
		" Id: %s\n"
		" Name: %s\n"
		" Rank: %s\n"
		" Date: %s\n",
		id.c_str(), name.c_str(), rank.c_str(), date.ToString().c_str());
}

void Certificate::EditByInput() {
	int option = -1;
	printf("Current id: %s\n. Input command(0 = edit, others = skip): ", id.c_str());
	cin >> option;
	cin.ignore();
	if (option == 0) {
		cout << "Input new id: ";
		string id;
		getline(cin, id);
		this->id = id;
	}

	printf("Current name: %s\n. Input command(0 = edit, others = skip): ", id.c_str());
	cin >> option;
	cin.ignore();
	if (option == 0) {
		cout << "Input new name: ";
		string name;
		getline(cin, name);
		this->name = name;
	}

	printf("Current rank: %s\n. Input command(0 = edit, others = skip): ", id.c_str());
	cin >> option;
	cin.ignore();
	if (option == 0) {
		cout << "Input new rank: ";
		string rank;
		getline(cin, rank);
		this->rank = rank;
	}

	printf("Current date: %s\n. Input command(0 = edit, others = skip): ", this->date.ToString().c_str());
	cin >> option;
	cin.ignore();
	if (option == 0) {
		cout << "Input new date: ";
		this->date = Helper::GetDateByInput();
	}
	cout << "End of certificate edit.\n";
}