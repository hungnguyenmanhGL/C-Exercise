#pragma once
#include <vector>
#include <memory>
#include "Student.h"
using namespace std;
class TuyenSinh
{
private:
	vector<shared_ptr<Student>> studentList;

public:
	TuyenSinh();

	~TuyenSinh();

	void ShowInfo();

	void AddStudent(shared_ptr<Student> student);

	shared_ptr<Student> GetById(const string& id);
};

