#pragma once
#include "Student.h"
class PartStudent :
    public Student
{
private:
    string city;

public:
    PartStudent();

    PartStudent(string id, string name, Date dob, int enrollYear, int entryScore, vector<StudyResult>& resList, string city);

    ~PartStudent() {};

    void ShowInfo() override;

    //getters
    string GetCity() { return this->city; }
};

