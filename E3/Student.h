#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <array>
using namespace std;

static const string TOAN = "Toan";
static const string LY = "Ly";
static const string HOA = "Hoa";
static const string SINH = "Sinh";
static const string VAN = "Van";
static const string SU = "Su";
static const string DIA = "Dia";

static const unordered_map<char, array<string, 3>> blockMap {
	{'A', {TOAN, LY, HOA}},
	{'B', {TOAN, HOA, SINH}},
	{'C', {VAN, SU, DIA}}
};

class Student
{
private:
	string id;
	string name;
	string address;
	int priority;
	char block;

public:
	Student();

	Student(string id, string name, string address, int priority, char block);

	void ShowInfo();

	~Student();

	string GetId() const;
};

