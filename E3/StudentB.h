#pragma once
#include "Student.h"
class StudentB :
    public Student
{
public:
    StudentB(string id, string name, string address, int priority);

    ~StudentB();

    void ShowInfo() override;
};

