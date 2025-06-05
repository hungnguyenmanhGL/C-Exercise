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
};

