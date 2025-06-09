#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "Date.h"
#include "Certificate.h"
using namespace std;

static const enum EmployeeType {
	INTERN = 0,
	FRESHER = 1,
	EXPERIENCE = 2
};

static const enum InfoEnum {
	ID = 0,
	NAME = 1,
	BIRTHDAY = 2,
	PHONE = 3,
	EMAIL = 4,
	TYPE = 5,
	CERT = 6,

	MAJOR = 10,
	SEMESTER = 11,
	UNIVERSITY = 12,

	GRADUATION_DATE = 20,
	GRADUATION_RANK = 21,
	EDUCATION = 22,

	EXP_YEAR = 30,
	PRO_SKILL = 31
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

	virtual void ShowInfo() = 0;

	void ShowCertificate();

	void AddCertificate(const Certificate& cert);

	void EditCertificateList();

	virtual void ShowEditPrompt();

	//Getters
	string GetId();

	string GetName();

	Date GetBirthday();

	string GetPhone();

	string GetEmail();

	EmployeeType GetType();

	vector<Certificate> GetCertificateList();

	//Setters
	void SetId(const string& id) { this->id = id; }

	void SetName(const string& name) { this->fullName = name; }

	void SetBirthday(const Date& date) { this->birthday = date; }

	void SetPhone(const string& phone) { this->phone = phone; }

	void SetEmail(const string& email) { this->email = email; }

	void SetType(const EmployeeType& type) { this->type = type; }

	void SetCertificateList(vector<Certificate>& cert) { this->certList = cert; }
};

