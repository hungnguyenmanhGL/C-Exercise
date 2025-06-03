#include "CanBo.h"

void CanBo::ShowInfo() {
    printf("First name: %s\n"
        "Last name: %s\n"
        "Age: %d\n"
        "Gender: %s\n"
        "Address: %s\n", firstName.c_str(), lastName.c_str(), age, genderMap[gender].c_str(), address.c_str());
}

CanBo::CanBo(string firstName, string lastName, int age, Gender gender, string address) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->age = age;
    this->gender = gender;
    this->address = address;
}

string CanBo::GetFirstName() const {
    return this->firstName;
}

string CanBo::GetLastName() const {
    return this->lastName;
}