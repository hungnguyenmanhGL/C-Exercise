#include <iostream>
#include "Manager.h"
#include "Employee.h"
#include "Intern.h"
#include "Helper.h"

int Employee::count = 0;

void MainLoop() {
	Manager manager;

	while (true) {
		cout << "Input command (0 = add/1 = show/2 = search & edit/ -1 = quit): ";
		int cmd = -1;
		cin >> cmd;
		cin.ignore();
		switch (cmd) {
		case Command::ADD:
		{
			int n;
			cout << "Number of employee to add. ";
			n = Helper::GetIntByInput(0);

			for (int i = 0; i < n; i++) {
				manager.AddByInput();
			}
			break;
		}

		case Command::SHOW:
		{
			int employType;
			printf("Input employee type to show (%d = %s, %d = %s, %d = %s, others = all): ",
				EmployeeType::INTERN, employTypeMap[EmployeeType::INTERN].c_str(),
				EmployeeType::FRESHER, employTypeMap[EmployeeType::FRESHER].c_str(),
				EmployeeType::EXPERIENCE, employTypeMap[EmployeeType::EXPERIENCE].c_str());
			cin >> employType;
			cin.ignore();

			switch (employType)
			{
			case EmployeeType::INTERN:
				manager.ShowInfoByType(EmployeeType::INTERN);
				break;
			case EmployeeType::FRESHER:
				manager.ShowInfoByType(EmployeeType::FRESHER);
				break;
			case EmployeeType::EXPERIENCE:
				manager.ShowInfoByType(EmployeeType::EXPERIENCE);
				break;
			default:
				manager.ShowInfo();
				break;
			}
			break;
		}

		case Command::SEARCH: {
			manager.SearchByInput();
			break;
		}
			

		case Command::QUIT:
		{
			cout << "Quitting..." << endl;
			break;
		}

		default:
		{
			cout << "Invalid command. Try again." << endl;
			break;
		}
		}
		if (cmd == QUIT) break;
	}
}

int main()
{
	MainLoop();
    return 0;
}
