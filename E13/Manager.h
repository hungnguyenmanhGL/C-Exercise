#pragma once
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <memory>
#include "Employee.h"
using namespace std;

const unordered_set<string> phoneStarterSet{
	"090", "098", "091", "031", "035", "038"
};

const unordered_set<string> emailEndSet{
	".com", ".net", ".org"
};

const unordered_set<char> invalidCharSet{
	'/', ',', '[', ']', '(', ')', '{', '}', ':', ';', '|'
};

class Manager
{
private:
	unordered_map<string,shared_ptr<Employee>> employMap;

	shared_ptr<Employee> GetById(const string& id);

	bool IsIdExisted(const string& id);

	bool IsPhoneValid(const string& phone);

	bool IsEmailValid(const string& email);

	void AddEmployeeByType(int type, string id, string name, Date birthday, string phone, string email);

public:
	Manager();

	~Manager();

	void AddByInput();

	string GetPhoneByInput();

	string GetEmailByInput();

	void ShowInfo();

	void SearchEditByInput();
};
