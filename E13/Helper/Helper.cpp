#include "Helper.h"
#include "DateException.h"
#include "PhoneException.h"
#include "EmailException.h"
#include "FullNameException.h"

Date Helper::GetDateByInput() {
	int day, month, year;
	bool isValidDate = false;
	cout << "Input date:" << endl;
	while (!isValidDate) {
		try {
			cout << " Day: ";
			cin >> day;
			if (cin.fail()) throw runtime_error("Invalid input for int.");
			cin.ignore();

			cout << " Month: ";
			cin >> month;
			if (cin.fail()) throw runtime_error("Invalid input for int.");
			cin.ignore();

			cout << " Year: ";
			cin >> year;
			if (cin.fail()) throw runtime_error("Invalid input for int.");
			cin.ignore();

			isValidDate = Helper::IsDateValid(day, month, year);
			if (!isValidDate) throw DateException("Invalid Date. Try again");
		}
		catch (DateException& dateExcept) {
			printf("Date Exception: %s\n", dateExcept.what());
		}
	}
	return Date(day, month, year);
}

string Helper::GetFullNameByInput() {
	string name;
	bool isValid = false;
	while (!isValid) {
		try {
			cout << "Full name: ";
			getline(cin, name);
			isValid = IsFullNameValid(name);
			if (!isValid) throw FullNameException("Invalid full name. Try again.");
		}
		catch (const FullNameException& nameExcept) {
			cout << "Full name exception: " << nameExcept.what() << endl;
		}
	}
	return name;
}

string Helper::GetPhoneByInput() {
	string phone;
	bool isValid = false;
	while (!isValid) {
		try {
			cout << "Phone number: ";
			getline(cin, phone);
			isValid = IsPhoneValid(phone);
			if (!isValid) throw PhoneException("Invalid phone number. Try again");
		}
		catch (const PhoneException& phoneExcept) {
			cout << "Phone exception: " << phoneExcept.what() << endl;
		}
	}
	return phone;
}

string Helper::GetEmailByInput() {
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

int Helper::GetTypeByInput() {
	int type;
	do {
		printf("Employee type (%d = Intern, %d = Fresher, %d = Experience): ",
			EmployeeType::INTERN, EmployeeType::FRESHER, EmployeeType::EXPERIENCE);
		cin >> type;
		cin.ignore();
		if (type < EmployeeType::INTERN || type > EmployeeType::EXPERIENCE)
			cout << "Invalid employee type. Try again." << endl;
	} while (type < EmployeeType::INTERN || type > EmployeeType::EXPERIENCE);
	return type;
}

int Helper::GetIntByInput(int lowerLim, int upperLim) {
	int res;
	if (lowerLim >= upperLim) {
		do {
			printf("Input value (value >= %d): ", lowerLim);
			cin >> res;
			if (cin.fail()) throw runtime_error("Invalid input for int.");
			cin.ignore();
			if (res < lowerLim) cout << "Invalid value. Try again" << endl;
		} while (res < lowerLim);
	}
	else {
		do {
			printf("Input value (%d <= value <= %d): ", lowerLim, upperLim);
			cin >> res;
			if (cin.fail()) throw runtime_error("Invalid input for int.");
			cin.ignore();
			if (res < lowerLim || res > upperLim) cout << "Invalid value. Try again" << endl;
		} while (res < lowerLim || res > upperLim);
	}
	return res;
}

Certificate Helper::GetCertificateByInput() {
	string id;
	string name;
	string rank;
	Date date;

	cout << "Certificate id: ";
	getline(cin, id);

	cout << "Certificate name: ";
	getline(cin, name);

	cout << "Certificate rank: ";
	getline(cin, rank);

	date = Helper::GetDateByInput();

	Certificate cert(id, name, rank, date);
	return cert;
}

bool Helper::IsFullNameValid(const string& name) {
	if (name.length() < 6) {
		cout << "Full name can't be fewer than 6 characters. Try again" << endl;
		return false;
	}
	if (name.length() > 50) {
		cout << "Max length for full name is 50 characters. Try again" << endl;
		return false;
	}
	return true;
}

bool Helper::IsDateValid(int day, int month, int year) {
	if (day <= 0 || month <= 0) {
		cout << "Day or month < 0" << endl;
		return false;
	}
	if (year < 1500) {
		cout << "Year < 1500" << endl;
		return false;
	}
	if (day > 31 || month > 12) {
		cout << "Day > 31 or month > 12" << endl;
		return false;
	}

	if (month == 2) {
		if (year % 4 == 0) {
			if (day > 29) cout << "Feb of leap year has 29 days" << endl;
			return day <= 29;
		}
		else {
			if (day > 28) cout << "Normal Feb only has 28 days" << endl;
			return day <= 28;
		}
	}

	if (Helper::Is31DayMonth(month)) return day <= 31;
	else return day <= 30;
}

bool Helper::IsPhoneValid(const string& phone) {
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

bool Helper::IsEmailValid(const string& email) {
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

bool Helper::Is31DayMonth(int month) {
	return month == 1 || month == 3 || month == 5 || month == 7 || month == 8
		|| month == 10 || month == 12;
}