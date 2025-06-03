#pragma once
#include "Officer.h"
class Engineer :
    public Officer
{
private:
    string major;

public:
    void ShowInfo() override;

    Engineer() {};

    Engineer(string firstName, string lastName, int age, Gender gender, string address);

    Engineer(string firstName, string lastName, int age, Gender gender, string address, string major);

    ~Engineer() {}
};

