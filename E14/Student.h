#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include "Helper.h"
using namespace std;

class Student
{
protected:
	string fullName;
	Date doB;
	Gender gender;
	string phone;
	string university;
	int gradeLevel;

	bool isGood;

public:
	Student() {};

	Student(string name, Date doB, Gender gender, string phone, string uni, int gradeLvl);

	virtual ~Student() {};

	virtual void ShowInfo();

	void ShowContactData();

	//getters
	string GetFullName() { return this->fullName; }

	string GetPhone() { return this->phone; }

	bool IsGood() { return this->isGood; }
};

