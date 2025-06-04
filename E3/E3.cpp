#include <iostream>
#include "Admission.h"
using namespace std;

static enum Command {
	ADD = 0,
	SHOW = 1,
	SEARCH = 2,
	QUIT = -1
};

Admission ad;

void MainLoop() {
	while (true) {
		cout << "Input command (0 = add/1 = show/2 = search/ -1 = quit): ";
		int cmd = -1;
		cin >> cmd;
		cin.ignore();
		switch (cmd) {
		case ADD:
		{
			ad.AddStudentByInput();
			break;
		}

		case SHOW:
		{
			ad.ShowInfo();
			break;
		}

		case SEARCH:
		{
			ad.SearchIdByInput();
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