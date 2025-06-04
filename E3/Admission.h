#pragma once
#include <vector>
#include <memory>
#include "Student.h"
using namespace std;
class Admission
{
private:
	vector<shared_ptr<Student>> studentList;

public:
	Admission();

	~Admission();

	void ShowInfo();

	void AddStudent(shared_ptr<Student> student);

	void AddStudentByInput();

	void SearchIdByInput();

	shared_ptr<Student> GetById(const string& id);
};

