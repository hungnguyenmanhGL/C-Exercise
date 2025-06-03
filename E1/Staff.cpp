#include "Staff.h"

void Staff::ShowInfo() {
    Officer::ShowInfo();
    printf("Position: %s\n", position.c_str());
}

Staff::Staff(string firstName, string lastName, int age, Gender gender, string address) 
    : Officer(firstName, lastName, age, gender, address) {}

Staff::Staff(string firstName, string lastName, int age, Gender gender, string address, string position) 
    : Officer(firstName, lastName, age, gender, address) {
    this->position = position;
}
