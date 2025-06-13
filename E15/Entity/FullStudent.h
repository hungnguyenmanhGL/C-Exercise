#pragma once
#include "Student.h"
class FullStudent :
    public Student
{
public:
    FullStudent();

    FullStudent(string id, string name, Date dob, int enrollYear, int entryScore, vector<StudyResult>& resList);

    ~FullStudent() {};
};

