#include "Intern.h"

Intern::Intern() : Employee() {}

Intern::Intern(string id, string fullName, Date birthday, string phone, string email, EmployeeType type,
    string major, int semester, string university)
    : Employee(id, fullName, birthday, phone, email, type) {
    this->major = major;
    this->semester = semester;
    this->university = university;
}

Intern::~Intern() {}

void Intern::ShowInfo() {
    Employee::ShowInfo();
    printf("Intern-specific: \n"
        " Major: %s\n"
        " Semester: %d\n"
        " University: %s\n",
        major.c_str(), semester, university.c_str());
}