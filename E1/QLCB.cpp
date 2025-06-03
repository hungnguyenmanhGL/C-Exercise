#include "QLCB.h"

void QLCB::AddEmployee(shared_ptr<CanBo> canBo) {
	employList.push_back(canBo);
}

vector<shared_ptr<CanBo>> QLCB::GetEmployeeByName(const string firstName, const string lastName) {
	vector<shared_ptr<CanBo>> result;
	for (shared_ptr<CanBo>& canbo : employList) {
		if (canbo->GetFirstName()._Equal(firstName) && canbo->GetLastName()._Equal(lastName)) {
			result.push_back(canbo);
		}
	}
	return result;
}

void QLCB::ShowInfo() {
	for (shared_ptr<CanBo>& canbo : employList) {
		canbo->ShowInfo();
	}
	cout << "End Of List" << endl << endl;
}