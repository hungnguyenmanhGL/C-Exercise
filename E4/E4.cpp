#include <iostream>
#include "Quarter.h"
using namespace std;

static enum Command {
	ADD = 0,
	SHOW = 1,
	SEARCH = 2,
	QUIT = -1
};

Quarter quarter;

void MainLoop() {
	while (true) {
		cout << "Input command (0 = add/1 = show/ -1 = quit): ";
		int cmd = -1;
		cin >> cmd;
		switch (cmd) {
		case ADD:
		{
			int n;
			cout << "Number of houses to add: ";
			cin >> n;
			if (n <= 0) cout << "Invalid number. Try again";

			for (int i = 0; i < n; i++) {
				quarter.AddHouseByInput();
			}
			break;
		}

		case SHOW:
		{
			quarter.ShowInfo();
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

