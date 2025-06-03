#pragma once
#include "CanBo.h"
class KiSu :
    public CanBo
{
private:
    string major;

public:
    void ShowInfo() override;

    KiSu() {};

    KiSu(string firstName, string lastName, int age, Gender gender, string address);

    KiSu(string firstName, string lastName, int age, Gender gender, string address, string major);

    ~KiSu() {}
};

