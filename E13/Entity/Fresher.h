#pragma once
#include "Employee.h"
#include "Date.h"
class Fresher :
    public Employee
{
private:
    Date graduationDate;
    string graduationRank;
    string education;

public:
    Fresher();

    Fresher(string id, string fullName, Date birthday, string phone, string email, EmployeeType type,
        Date graduationDate, string graduationRank, string education);

    ~Fresher();

    void ShowInfo() override;

    void ShowEditPrompt() override;

    //setter
    void SetGraduationDate(const Date& date) { this->graduationDate = graduationDate; }

    void SetGraduationRank(const string& rank) { this->graduationRank = rank; }

    void SetEducation(const string& edu) { this->education = edu; }
};

