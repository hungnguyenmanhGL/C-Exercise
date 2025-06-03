#pragma once
#include "Officer.h"
#include <iostream>
class Worker :
    public Officer
{
    private:
    int level;

    public:
    Worker() {};

    Worker(string firstName, string lastName, int age, Gender gender, string address, int level);

    void ShowInfo() override;

    static bool IsLevelValid(int level);

    ~Worker() {}
};

