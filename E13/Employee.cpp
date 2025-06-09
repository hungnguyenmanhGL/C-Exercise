#include "Employee.h"
#include <stdio.h>
#include "Helper.h"
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

string Employee::GetName() {
	return this->fullName;
}

Date Employee::GetBirthday() {
	return this->birthday;
}

string Employee::GetPhone() {
	return this->phone;
}

string Employee::GetEmail() {
	return this->email;
}

EmployeeType Employee::GetType() {
	return this->type;
}

vector<Certificate> Employee::GetCertificateList() {
	return move(this->certList);
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
	ShowCertificate();
}

void Employee::ShowCertificate() {
	printf("%d certificate(s).\n", (int)certList.size());
	if (certList.size() == 0) return;
	for (int i = 0; i < certList.size(); i++) {
		printf("Certificate index %d info:\n", i);
		certList[i].ShowInfo();
	} printf("End of Certificate List.\n");
}

void Employee::AddCertificate(const Certificate& cert) {
	certList.push_back(cert);
}

void Employee::EditCertificateList() {
	int cmd;
	do {
		printf("Edit certificates. Input command (%d = edit, %d = delete, %d = add, %d = back): ",
			SearchSubCommand::EDIT, SearchSubCommand::SUB_DELETE, SearchSubCommand::SUB_ADD, SearchSubCommand::BACK);
		cin >> cmd;
		cin.ignore();

		switch (cmd)
		{
		case SearchSubCommand::SUB_ADD: {
			cout << "Input values for new certificate.\n";
			Certificate cert = Helper::GetCertificateByInput();
			certList.push_back(cert);
			break;
		}
		case SearchSubCommand::SUB_DELETE: {
			if (certList.size() == 0) {
				cout << "0 certificate to delete." << endl;
				break;
			}
			ShowCertificate();
			int index;
			cout << "Input certificate index to delete. ";
			index = Helper::GetIntByInput(0, certList.size() - 1);
			auto it = certList.begin() + index;
			certList.erase(it);
			cout << "Deleted certificate index " << index << endl;
			break;
		}
		case SearchSubCommand::EDIT: {
			if (certList.size() == 0) {
				cout << "0 certificate to delete." << endl;
				break;
			}
			ShowCertificate();
			int index;
			cout << "Input certificate index to delete. ";
			index = Helper::GetIntByInput(0, certList.size() - 1);
			Certificate& cert = certList[index];
		}
		case SearchSubCommand::BACK: {
			cout << "Stop editting certificate.\n";
			break;
		}
		default:
			cout << "Invalid command. Try again.\n";
			break;
		}

	} while (cmd != SearchSubCommand::BACK);
}

void Employee::ShowEditPrompt() {
	printf("Input index to edit. Check the listed index below, input any other values to quit.\n"
		" Common info: %d = id, %d = name, %d = birthday, %d = phone, %d = email, %d = type, %d = cert\n",
		InfoEnum::ID, InfoEnum::NAME, InfoEnum::BIRTHDAY, InfoEnum::PHONE, InfoEnum::EMAIL, InfoEnum::TYPE, InfoEnum::CERT);
}
