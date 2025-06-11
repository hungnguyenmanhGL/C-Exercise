#pragma once
#include "Student.h"
class NormalStudent :
    public Student
{
private: 
    int englishScore; //is TOEIC score, 0 <= value <= 990
    int entryScore; // 0 <= value <= 10

public:
    NormalStudent();

    NormalStudent(string name, Date doB, Gender gender, string phone, string uni, int gradeLvl, int englishScore, int entryScore);

    ~NormalStudent() {};

    void ShowInfo() override;

    //getters
    int GetEnglishScore() { return this->englishScore; }

    int GetEntryScore() { return this->entryScore; }
};

