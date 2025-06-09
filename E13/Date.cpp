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