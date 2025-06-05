#include <iostream>
#include "Manager.h"
#include "Employee.h"
#include "Intern.h"

int Employee::count = 0;

static enum Command {
    ADD = 0,
    SHOW = 1,
    SEARCH = 2,
    QUIT = -1
};

void MainLoop() {
	Manager manager;

	while (true) {
		cout << "Input command (0 = add/1 = show/ -1 = quit): ";
		int cmd = -1;
		cin >> cmd;
		cin.ignore();
		switch (cmd) {
		case ADD:
		{
			int n;
			cout << "Number of employee to add: ";
			cin >> n;
			cin.ignore();
			if (n <= 0) cout << "Invalid number. Try again";

			for (int i = 0; i < n; i++) {
				manager.AddByInput();
			}
			break;
		}

		case SHOW:
		{
			manager.ShowInfo();
			break;
		}

		case QUIT:
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
