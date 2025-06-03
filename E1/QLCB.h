#pragma once
#include "CanBo.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class QLCB {
private:
	vector<shared_ptr<CanBo>> employList;

public:
	QLCB() {}

	~QLCB() {}

	void AddEmployee(shared_ptr<CanBo> canBo);

	vector<shared_ptr<CanBo>> GetEmployeeByName(const string firstName, const string lastName);

	void ShowInfo();
};
