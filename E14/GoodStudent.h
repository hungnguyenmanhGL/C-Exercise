#pragma once
#include "Student.h"
class GoodStudent :
    public Student
{
private:
    float gpa;
    string bestReward;

public:
    GoodStudent();

    GoodStudent(string name, Date doB, Gender gender, string phone, string uni, int gradeLvl, float gpa, string bestReward);

    ~GoodStudent() {};

    void ShowInfo() override;

    //getters
    float GetGpa() { return this->gpa; }
};

