#pragma once
#include "Officer.h"
class Staff :
    public Officer
{
private:
    string position;

public:
    void ShowInfo() override;

    Staff() {};

    Staff(string firstName, string lastName, int age, Gender gender, string address);

    Staff(string firstName, string lastName, int age, Gender gender, string address, string position);

    ~Staff() {}
};

