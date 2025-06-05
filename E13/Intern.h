#pragma once
#include "Employee.h"
class Intern :
    public Employee
{
private:
    string major;
    int semester;
    string university;

public:
    Intern();

    Intern(string id, string fullName, Date birthday, string phone, string email, EmployeeType type, 
        string major, int semester, string univeristy);

    ~Intern();

    void ShowInfo() override;
};

