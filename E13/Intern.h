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

    void ShowEditPrompt() override;

    //setter
    void SetMajor(const string& major) { this->major = major; }
    
    void SetSemester(const int& semester) { this->semester = semester; }

    void SetUniversity(const string& university) { this->university = university; }
};

