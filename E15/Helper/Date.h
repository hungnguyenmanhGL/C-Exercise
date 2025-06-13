#pragma once
#include <string>
using namespace std;

class Date
{

public:
	int day;
	int month;
	int year;

	Date() {}

	~Date() {}

	Date(int day, int month, int year) : day(day), month(month), year(year) {}

	string ToString();
};

