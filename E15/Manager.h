#pragma once
#include "Faculty.h"
class Manager
{
private:
	vector<Faculty> facultyList;

	void AddStudent(int facultyIndex, shared_ptr<Student> student);

	void AddTestData();

public:
	Manager();

	~Manager() {};

	void AddStudentByInput();

	void AddFaculty(const string& name);

	void PrintFacultyIndexPrompt();

	void ShowAll();

	void ShowFullCountFaculty();

	void ShowStudentsWithHighestEntry();

	void ShowPartStudentsFromCity(const string& city);

	void ShowStudentsWithLastSemesterAboveEight();

	void ShowStudentsWithHighestSemesterScore();

	void ShowEnrollCountInYear(const int& year);

};

