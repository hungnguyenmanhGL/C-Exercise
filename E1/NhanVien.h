#pragma once
#include "CanBo.h"
class NhanVien :
    public CanBo
{
private:
    string position;

public:
    void ShowInfo() override;

    NhanVien() {};

    NhanVien(string firstName, string lastName, int age, Gender gender, string address);

    NhanVien(string firstName, string lastName, int age, Gender gender, string address, string position);

    ~NhanVien() {}
};

