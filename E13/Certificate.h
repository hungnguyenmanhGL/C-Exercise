#pragma once
#include <string>
#include "Date.h"
using namespace std;
class Certificate
{
private:
	string id;
	string name;
	int rank;
	Date date;

public:
	Certificate() {};

	Certificate(string id, string name, int rank, Date date);

	~Certificate() {};

	void ShowInfo();
};

