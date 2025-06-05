#pragma once
#include "Employee.h"
class Experience :
    public Employee
{
private:
    int expYear;
    string proSkill;

public:
    Experience();

    Experience(string id, string fullName, Date birthday, string phone, string email, EmployeeType type, int expYear, string proSkill);

    ~Experience();

    void ShowInfo() override;
};

