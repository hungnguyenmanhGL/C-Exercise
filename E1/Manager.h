#pragma once
#include "Officer.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Manager {
private:
	vector<shared_ptr<Officer>> employList;

public:
	Manager() {}

	~Manager() {}

	void AddEmployee(shared_ptr<Officer> canBo);

	vector<shared_ptr<Officer>> GetEmployeeByName(const string lastName);

	void ShowInfo();
};
