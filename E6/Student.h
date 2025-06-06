#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

class Student
{
private:
	string name;
	int age;
	string birthplace;
	string className;

public:
	Student();

	Student(string id, int age, string birthplace, string className);

	void ShowInfo();

	~Student();

	void SetName(string name);

	void SetAge(int age);

	int GetAge();

	void SetBirthplace(string birthplace);

	string GetBirthplace();

	void SetClass(string className);
};

