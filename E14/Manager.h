#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <vector>
#include <memory>
#include "Student.h"
#include "GoodStudent.h"
#include "NormalStudent.h"
#include "Helper.h"
using namespace std;

class Manager
{
private:
	vector<shared_ptr<GoodStudent>> goodList;
	vector<shared_ptr<NormalStudent>> normalList;

public:
	Manager() {};
	~Manager() {};

	void ReadFromFile(const string& path);

	void ShowAll();

	void ShowAllContactData();

	vector<shared_ptr<Student>> GetCandidateList(int num);
};

