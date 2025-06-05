#pragma once
#include <iostream>
#include <vector>
#include <unordered_set>
#include "Household.h"
using namespace std;

class Quarter
{
private:
	vector<Household> houseList;
	unordered_set<string> idSet;

public:
	Quarter() {}
	~Quarter() {}

	void AddHouse(Household& house);

	void AddHouseByInput();

	void ShowInfo();
};

