#pragma once
#include <string>
#include "Date.h"
using namespace std;
class Certificate
{
private:
	string id;
	string name;
	string rank;
	Date date;

public:
	Certificate() {};

	Certificate(string id, string name, string rank, Date date);

	~Certificate() {};

	void ShowInfo();

	void EditByInput();
};

