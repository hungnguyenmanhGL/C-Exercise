#include "Fresher.h"

Fresher::Fresher() : Employee() {}

Fresher::Fresher(string id, string fullName, Date birthday, string phone, string email, EmployeeType type,
    Date graduationDate, string graduationRank, string education)
    : Employee(id, fullName, birthday, phone, email, type) {
    this->graduationDate = graduationDate;
    this->graduationRank = graduationRank;
    this->education = education;
}

Fresher::~Fresher() {}

void Fresher::ShowInfo() {
    Employee::ShowInfo();
    printf("Fresher-specific: \n"
        " Graduation date: %s\n"
        " Graduation rank: %d\n"
        " Education: %s\n",
        graduationDate.ToString().c_str(), graduationRank.c_str(), education.c_str());
}