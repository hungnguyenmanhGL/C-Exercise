#include "Employee.h"
#include <stdio.h>
using namespace std;

Employee::Employee() { count++; }

Employee::Employee(string id, string fullName, Date birthday, string phone, string email, EmployeeType type) 
	: id(id), fullName(fullName), birthday(birthday), phone(phone), email(email), type(type) {
	count++;
	printf("+1 employee. Current count: %d\n", count);
}

Employee::~Employee() {
	count--;
	printf("-1 employee. Current count: %d\n", count);
}

string Employee::GetId() {
	return this->id;
}

void Employee::ShowInfo() {
	printf("Id: %s\n"
		" Name: %s\n"
		" Birthday: %s\n"
		" Phone: %s\n"
		" Email: %s\n"
		" Type: %s\n",
		id.c_str(), fullName.c_str(), birthday.ToString().c_str(), 
		phone.c_str(), email.c_str(), employTypeMap[type].c_str());
}

void Employee::AddCertificate(const Certificate& cert) {
	certList.push_back(cert);
}