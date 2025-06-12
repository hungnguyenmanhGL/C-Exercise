#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include "Date.h"
#include "StudyResult.h"
using namespace std;

class Student
{
protected:
	string id;
	string name;
	Date dob;
	int enrollYear;
	int entryScore;
	vector<StudyResult> resultList;

	bool isFullTime;

public:
	Student() {};

	Student(string id, string name, Date dob, int enrollYear, int entryScore, vector<StudyResult>& resList);

	Student(Student& s);

	virtual ~Student() {};

	virtual void ShowInfo();

	void ShowStudyResults();

	bool IsLastSemesterScoreAbove(float score);

	float GetHighestSemesterScore();

	//getters
	bool IsFullTime() { return this->isFullTime; }

	int GetEntryScore() { return this->entryScore; }

	int GetEnrollYear() { return this->enrollYear; }
};

