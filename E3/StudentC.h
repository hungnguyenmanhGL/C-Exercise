#pragma once
#include "Student.h"
class StudentC :
    public Student
{
public:
    StudentC(string id, string name, string address, int priority);

    ~StudentC();

    void ShowInfo() override;
};

