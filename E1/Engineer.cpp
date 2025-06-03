#include "Engineer.h"

void Engineer::ShowInfo() {
    Officer::ShowInfo();
    printf("Major: %s\n", major.c_str());
}

Engineer::Engineer(string firstName, string lastName, int age, Gender gender, string address) 
    : Officer(firstName, lastName, age, gender, address) {

}

Engineer::Engineer(string firstName, string lastName, int age, Gender gender, string address, string major) 
    : Officer(firstName, lastName, age, gender, address) {
    this->major = major;
}