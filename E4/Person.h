#pragma once
#include <string>
using namespace std;

class Person
{
private:
	string name;
	int age;
	string job;
	string id;

public:
	Person(string name, int age, string job, string id);
	~Person();

	void ShowInfo();

};

