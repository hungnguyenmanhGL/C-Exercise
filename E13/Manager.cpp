#include "Manager.h"
#include "DateException.h"
#include "PhoneException.h"
#include "EmailException.h"
#include "Intern.h"
#include "Fresher.h"
#include "Experience.h"


Manager::Manager() {}

Manager::~Manager() {}

shared_ptr<Employee> Manager::GetById(const string& id) {
	if (employMap.find(id) != employMap.end()) return employMap[id];
	return nullptr;
}

void Manager::ShowInfo() {
	for (pair<string, shared_ptr<Employee>> p : employMap) {
		p.second->ShowInfo();
	} cout << "End of List" << endl;
}

void Manager::AddByInput() {
	string id;
	do {
		cout << "Id: ";
		getline(cin, id);
		if (employMap.find(id) != employMap.end()) cout << "Id already existed." << endl;
	} while (employMap.find(id) != employMap.end());

	string name;
	cout << "Name: ";
	getline(cin, name);

	Date birthday = Date::GetDateByInput();

	string phone = GetPhoneByInput();

	string email = GetEmailByInput();

	int type;
	do {
		cout << "Employee type: "; 
		cin >> type;
		cin.ignore();
		if (type < EmployeeType::INTERN || type > EmployeeType::EXPERIENCE)
			cout << "Invalid type. Try again." << endl;
		else
			AddEmployeeByType(type, id, name, birthday, phone, email);
	} while (type < EmployeeType::INTERN || type > EmployeeType::EXPERIENCE);
}

string Manager::GetPhoneByInput() {
	string phone;
	bool isValid = false;
	while (!isValid) {
		try {
			cout << "Phone number: ";
			getline(cin, phone);
			isValid = IsPhoneValid(phone);
			if (!isValid) throw PhoneException("Invalid phone number. Try again");
		}
		catch(const PhoneException& phoneExcept) {
			cout << "Phone exception: " << phoneExcept.what() << endl;
		}
	}
	return phone;
}

string Manager::GetEmailByInput() {
	string email;
	bool isValid = false;
	while (!isValid) {
		try {
			cout << "Email: ";
			getline(cin, email);
			isValid = IsEmailValid(email);
			if (!isValid) throw EmailException("Invalid email number. Try again");
		}
		catch (const EmailException& emailExcept) {
			cout << "Email exception: " << emailExcept.what() << endl;
		}
	}
	return email;
}

void Manager::AddEmployeeByType(int type, string id, string name, Date birthday, string phone, string email) {
	switch (type)
	{
	case EmployeeType::INTERN: {
		string major;
		int semester;
		string university;

		cout << "Major: ";
		getline(cin, major);

		cout << "Semester: ";
		cin >> semester;
		cin.ignore();

		cout << "University: ";
		getline(cin, university);

		shared_ptr<Employee> intern(new Intern(id, name, birthday, phone, email, EmployeeType::INTERN,
			major, semester, university));
		employMap.insert(pair<string, shared_ptr<Employee>>(id, intern));
		cout << "Added 1 new Intern." << endl;
		break;
	}
	case EmployeeType::FRESHER: {
		Date graduationDate;
		string graduationRank;
		string education;

		graduationDate = Date::GetDateByInput();

		cout << "Graduation rank: ";
		getline(cin, graduationRank);

		cout << "Education: ";
		getline(cin, education);

		shared_ptr<Employee> fresher(new Fresher(id, name, birthday, phone, email, EmployeeType::FRESHER,
			graduationDate, graduationRank, education));
		employMap.insert(pair<string, shared_ptr<Employee>>(id, fresher));
		cout << "Added 1 new Fresher." << endl;
		break;
	}

	case EmployeeType::EXPERIENCE: {
		int expYear;
		string proSkill;

		do {
			cout << "Year of experience: ";
			cin >> expYear;
			if (cin.fail()) throw runtime_error("Invalid input for int");
			cin.ignore();
			if (expYear <= 0) cout << "Invalid input. Try again.";
		} while (expYear <= 0);

		cout << "Professional skill: ";
		getline(cin, proSkill);

		shared_ptr<Employee> exp(new Experience(id, name, birthday, phone, email, EmployeeType::FRESHER,
			expYear, proSkill));
		employMap.insert(pair<string, shared_ptr<Employee>>(id, exp));
		cout << "Added 1 new Experience." << endl;
		break;
	}
	default:
		break;
	}
}

bool Manager::IsPhoneValid(const string& phone) {
	if (phone.size() != 10) {
		cout << "Number must have exactly 10 digits" << endl;
		return false;
	}

	if (phoneStarterSet.find(phone.substr(0, 3)) == phoneStarterSet.end()) {
		cout << "Invalid 3 starting digit. Must be 090, 098, 091, 031, 035, 038." << endl;
		return false;
	}
	return true;
}

bool Manager::IsEmailValid(const string& email) {
	bool hasSymbol = false;
	for (int i = 0; i < email.length(); i++) {
		if (email[i] == '@') {
			if (hasSymbol) {
				cout << "Email can't have more than 1 @." << endl;
				return false;
			}
			if (i == 0) {
				cout << "@ can't be the first character." << endl;
				return false;
			}
			hasSymbol = true;
		}
		if (invalidCharSet.find(email[i]) != invalidCharSet.end()) {
			cout << "Character " << email[i] << " is not allowed in email." << endl;
			return false;
		}
	}
	
	int tldStart = email.length() - 1 - 3;
	if (emailEndSet.find(email.substr(tldStart, 4)) == emailEndSet.end()) {
		cout << "Top-level domain not found in email." << endl;
		return false;
	}
	return true;
}
