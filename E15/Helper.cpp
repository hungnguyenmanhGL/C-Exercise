#include "Helper.h"
#include "DateException.h"
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

float Helper::GetFloatByInput(float lowerLim, float upperLim) {
	float res;
	if (lowerLim >= upperLim) {
		do {
			printf("Input value (value >= %.2f): ", lowerLim);
			cin >> res;
			if (cin.fail()) throw runtime_error("Invalid input for float.");
			cin.ignore();
			if (res < lowerLim) cout << "Invalid value. Try again" << endl;
		} while (res < lowerLim);
	}
	else {
		do {
			printf("Input value (%.2f <= value <= %.2f): ", lowerLim, upperLim);
			cin >> res;
			if (cin.fail()) throw runtime_error("Invalid input for float.");
			cin.ignore();
			if (res < lowerLim || res > upperLim) cout << "Invalid value. Try again" << endl;
		} while (res < lowerLim || res > upperLim);
	}
	return res;
}

bool Helper::IsFullNameValid(const string& name) {
	if (name.length() < 6) {
		throw FullNameException("Min length for full name is 6 characters.\n");
		return false;
	}
	if (name.length() > 50) {
		throw FullNameException("Max length for full name is 50 characters.\n");
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
		cout << "Year " << year << " < 1500" << endl;
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

bool Helper::Is31DayMonth(int month) {
	return month == 1 || month == 3 || month == 5 || month == 7 || month == 8
		|| month == 10 || month == 12;
}

void Helper::PrintCommandList() {
	for (int i = 0; i <= Command::GET_ENROLL_COUNT_IN_YEAR; i++) {
		printf(" %d = %s\n", i, commandMap[(Command)i].c_str());
	}
	printf(" %d = %s\n", Command::QUIT, commandMap[Command::QUIT].c_str());
}

string Helper::GenRandomId(mt19937& gen) {
	static int counter = 1000;
	return "ST" + to_string(counter++);
}

string Helper::GenRandomName(mt19937& gen) {
	vector<string> firstNames = { "Nguyen", "Tran", "Le", "Pham", "Hoang", "Dao", "Bui", "Vo" };
	vector<string> middleNames = { "Van", "Thi", "Duc", "Minh", "Thu", "Ngoc", "Quang" };
	vector<string> lastNames = { "Anh", "Binh", "Chau", "Diep", "Giang", "Hau", "Khoa", "Lam" };

	uniform_int_distribution<> distFirst(0, firstNames.size() - 1);
	uniform_int_distribution<> distMiddle(0, middleNames.size() - 1);
	uniform_int_distribution<> distLast(0, lastNames.size() - 1);

	return firstNames[distFirst(gen)] + " " + middleNames[distMiddle(gen)] + " " + lastNames[distLast(gen)];
}

Date Helper::GenRandomDob(mt19937& gen) {
	uniform_int_distribution<> distDay(1, 28);
	uniform_int_distribution<> distMonth(1, 12);
	uniform_int_distribution<> distYear(1990, 2005);
	return Date(distDay(gen), distMonth(gen), distYear(gen));
}

vector<StudyResult> Helper::GenRandomStudyResults(mt19937& gen) {
	vector<StudyResult> res;
	uniform_int_distribution<> distSemesters(0, 8);
	uniform_real_distribution<> distScore(4.00f, 10.00f);

	int semesterCnt = distSemesters(gen);
	for (int i = 0; i <= semesterCnt; i++) {
		res.emplace_back(i, distScore(gen));
	}
	return res;
}

string Helper::GenRandomCity(mt19937& gen) {
	vector<string> cities = { "Hanoi", "Ho Chi Minh City", "Da Nang", "Can Tho", "Hai Phong", 
		"Lao Cai", "Kien Giang", "Ca Mau", "Phu Tho", "Thai Binh", 
		"Long An", "Thanh Hoa", "Hue", "Vinh Phuc"};
	uniform_int_distribution<> distCity(0, cities.size() - 1);
	return cities[distCity(gen)];
}

int Helper::GenRandomInt(mt19937& gen, int biggerThan, int smallerThan) {
	uniform_int_distribution<> distInt(biggerThan, smallerThan);
	int res = distInt(gen);
	return res;
}