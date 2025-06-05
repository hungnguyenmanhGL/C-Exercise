#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include "Date.h"
#include "Certificate.h"
using namespace std;

static enum EmployeeType {
	INTERN,
	FRESHER,
	EXPERIENCE
};

static unordered_map<EmployeeType, string> employTypeMap{
	{INTERN, "Intern"},
	{FRESHER, "Fresher"},
	{EXPERIENCE, "Experience"}
};

class Employee
{
protected:
	static int count;

	string id;
	string fullName;
	Date birthday;
	string phone;
	string email;
	EmployeeType type;
	vector<Certificate> certList;

public:
	Employee();

	Employee(string id, string fullName, Date birthday, string phone, string email, EmployeeType type);

	virtual ~Employee();

	string GetId();

	virtual void ShowInfo() = 0;

	void AddCertificate(const Certificate& cert);
};

