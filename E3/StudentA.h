#pragma once
#include "Student.h"
class StudentA :
    public Student
{
public:
    StudentA(string id, string name, string address, int priority);

    ~StudentA();

    void ShowInfo() override;
};

