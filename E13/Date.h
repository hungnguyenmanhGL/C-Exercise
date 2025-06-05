#pragma once
#include <string>
#include "DateException.h"
using namespace std;

class Date
{
private:
	static bool Is31DayMonth(int month) {
		return month == 1 || month == 3 || month == 5 || month == 7 || month == 8
			|| month == 10 || month == 12;
	}

public:
	int day;
	int month;
	int year;

	Date() {}

	~Date() {}

	Date(int day, int month, int year) : day(day), month(month), year(year) {}

	string ToString();

	static bool IsValidDate(int day, int month, int year);

	static Date GetDateByInput();
};

