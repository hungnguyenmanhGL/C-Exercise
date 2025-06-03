#include "Manager.h"

void Manager::AddEmployee(shared_ptr<Officer> employee) {
	employList.push_back(employee);
}

vector<shared_ptr<Officer>> Manager::GetEmployeeByName(const string lastName) {
	vector<shared_ptr<Officer>> result;
	for (shared_ptr<Officer>& employee : employList) {
		if (employee->GetLastName()._Equal(lastName)) {
			result.push_back(employee);
		}
	}
	return result;
}

void Manager::ShowInfo() {
	if (employList.size() == 0) {
		cout << "No data on list." << endl;
		return;
	}

	for (shared_ptr<Officer>& employee : employList) {
		employee->ShowInfo();
	}
	cout << "End Of List" << endl << endl;
}