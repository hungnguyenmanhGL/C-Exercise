#include "Date.h"
#include <iostream>
using namespace std;

string Date::ToString() {
	string strDay = to_string(day);
	if (day < 10) strDay.insert(0, "0");
	string strMonth = to_string(month);
	if (month < 10) strMonth.insert(0, "0");
	return strDay + "/" + strMonth + "/" + to_string(year);
}

bool Date::IsValidDate(int day, int month, int year) {
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

	if (Is31DayMonth(month)) return day <= 31;
	else return day <= 30;
}

Date Date::GetDateByInput() {
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

			isValidDate = Date::IsValidDate(day, month, year);
			if (!isValidDate) throw DateException("Invalid Date. Try again");
		}
		catch (DateException& dateExcept) {
			printf("Date Exception: %s\n", dateExcept.what());
		}
	}
	return Date(day, month, year);
}