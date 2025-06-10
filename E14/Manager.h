#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <vector>
#include <memory>
#include "Student.h"
#include "Helper.h"
using namespace std;

class Manager
{
private:
	vector<shared_ptr<Student>> studentList;

public:
	Manager() {};
	~Manager() {};

	void ReadFromFile(const string& path);

	void ShowAll();
};

