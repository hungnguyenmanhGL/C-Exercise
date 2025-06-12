#pragma once
#include <string>
#include <stdio.h>
using namespace std;
class StudyResult
{
private:
	int semester;
	float avgScore;

public:
	StudyResult() {};

	StudyResult(int semester, float avgScore) : semester(semester), avgScore(avgScore) {};

	~StudyResult() {};

	void Print();
	
	//getters
	int GetSemester() { return this->semester; }
	float GetAvgScore() { return this->avgScore; }
};


