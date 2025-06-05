#pragma once
#include <vector>
#include <memory>
#include "Person.h";
using namespace std;

class Household
{
private:
	int no;
	vector<Person> memberList;

public:
	Household(int no);

	void AddMember(Person& person);

	void ShowInfo();

	~Household();
};

