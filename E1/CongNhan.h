#pragma once
#include "CanBo.h"
#include <iostream>
class CongNhan :
    public CanBo
{
    private:
    int level;

    public:
    CongNhan() {};

    CongNhan(string firstName, string lastName, int age, Gender gender, string address) : CanBo(firstName, lastName, age, gender, address) {
        this->level = 1;
    }

    CongNhan(string firstName, string lastName, int age, Gender gender, string address, int level) : CanBo(firstName, lastName, age, gender, address) {
        if (level < 1 || level > 10) {
            std::cout << "[CongNhan] CongNhan's level must be between 1 and 10. Level will be 1 by default" << endl;
            this->level = 1;
        }
        else this->level = level;
    }

    void ShowInfo() override {
        CanBo::ShowInfo();
        printf("Level: %d\n", level);
    }

    ~CongNhan() {}
};

