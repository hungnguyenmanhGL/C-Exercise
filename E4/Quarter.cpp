#include "Quarter.h"
using namespace std;

void Quarter::AddHouse(Household& house) {
	houseList.push_back(house);
}

void Quarter::ShowInfo() {
	if (houseList.size() == 0) {
		cout << "No data to show." << endl;
		return;
	}
	for (Household& house : houseList) {
		house.ShowInfo();
	}
}

void Quarter::AddHouseByInput() {
	int no;
	cout << "House no. : ";
	cin >> no;

	Household house{ no };
	
	int memberCount;
	cout << "Member count: ";
	cin >> memberCount;
	cin.ignore();

	for (int i = 0; i < memberCount; i++) {
		string name;
		cout << "Name: ";
		getline(cin, name);

		int age;
		do {
			cout << "Age: ";
			cin >> age;
			if (age <= 0) cout << "Invalid age. Try again";
		} while (age <= 0);
		cin.ignore();

		string job;
		cout << "Occupation: ";
		getline(cin, job);

		string id;
		do {
			cout << "Id: ";
			getline(cin, id);
			if (idSet.count(id) > 0) cout << "Id " << id << " existed. Try again." << endl;
		} while (idSet.count(id) > 0);

		Person person{ name, age, job, id };
		house.AddMember(person);
		cout << "Member added to house no. " << no << endl << endl;
	}
	houseList.push_back(house);
	cout << "House no. " << no << " added." << endl;
}