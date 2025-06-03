#include "KiSu.h"

void KiSu::ShowInfo() {
    CanBo::ShowInfo();
    printf("Major: %s\n", major.c_str());
}

KiSu::KiSu(string firstName, string lastName, int age, Gender gender, string address) 
    : CanBo(firstName, lastName, age, gender, address) {

}

KiSu::KiSu(string firstName, string lastName, int age, Gender gender, string address, string major) 
    : CanBo(firstName, lastName, age, gender, address) {
    this->major = major;
}