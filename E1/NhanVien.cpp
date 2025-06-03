#include "NhanVien.h"

void NhanVien::ShowInfo() {
    CanBo::ShowInfo();
    printf("Position: %s\n", position.c_str());
}

NhanVien::NhanVien(string firstName, string lastName, int age, Gender gender, string address) 
    : CanBo(firstName, lastName, age, gender, address) {}

NhanVien::NhanVien(string firstName, string lastName, int age, Gender gender, string address, string position) 
    : CanBo(firstName, lastName, age, gender, address) {
    this->position = position;
}
