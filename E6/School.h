#pragma once
#include <iostream>
#include <vector>
#include "Student.h"
using namespace std;

class School
{
private:
	vector<Student> studentList;

	void AddStudent(Student& student);

public:
	School();
	~School();

	void ShowAge20();

	void ShowAge23DaNang();

	void InputAdd();
};

