#pragma once
#include <memory>
#include "Student.h"
#include "FullStudent.h"
#include "PartStudent.h"

class Faculty
{
	string name;
	vector<shared_ptr<Student>> studentList;

public:
	Faculty() {};

	Faculty(string name);

	~Faculty() {};

	void AddStudent(shared_ptr<Student>& student);

	void ShowOrderedInfo();

	int GetFullTimeCount();

	shared_ptr<Student> GetHighestEntryScoreStudent();

	vector<shared_ptr<Student>> GetPartStudentListFromCity(const string& city);

	vector<shared_ptr<Student>> GetStudentListWithLastSemesterScoreAbove();

	shared_ptr<Student> GetStudentWithHighestSemesterScore();

	int GetStudentCountByEnrollYear(const int& year);

	void PrintName();
	//getters
	string GetName() { return this->name; }
};

struct StudentComparator
{
	bool operator()(shared_ptr<Student>& a, shared_ptr<Student>& b) {
		if (a->IsFullTime() && !b->IsFullTime())
			return false;
		if (!a->IsFullTime() && b->IsFullTime())
			return true;

		//if same type of student -> sort descending by enroll year
		return a->GetEnrollYear() < b->GetEnrollYear();
	}
};
