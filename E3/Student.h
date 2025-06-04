#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <array>
using namespace std;

static enum Block {
	A = 0,
	B = 1,
	C = 2
};

static const char blockA = 'A';
static const char blockB = 'B';
static const char blockC = 'C';

static const string TOAN = "Toan";
static const string LY = "Ly";
static const string HOA = "Hoa";
static const string SINH = "Sinh";
static const string VAN = "Van";
static const string SU = "Su";
static const string DIA = "Dia";

static const unordered_map<char, array<string, 3>> blockMap {
	{blockA, {TOAN, LY, HOA}},
	{blockB, {TOAN, HOA, SINH}},
	{blockC, {VAN, SU, DIA}}
};

class Student
{
protected:
	string id;
	string name;
	string address;
	int priority;

public:
	Student();

	Student(string id, string name, string address, int priority);

	virtual ~Student();

	virtual void ShowInfo();

	string GetId();
};

