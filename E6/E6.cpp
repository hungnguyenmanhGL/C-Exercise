#include <iostream>
#include "School.h"
using namespace std;

static enum Command {
    ADD = 0,
    SHOW20 = 1,
    SHOW23DN = 2,
    QUIT = -1
};

void MainLoop() {
    School school;

    while (true) {
        int cmd;
        cout << "Input command(0 = add, 1 = show age 20, 2 = show age 23 DaNang, -1 = quit): ";
        cin >> cmd;
        cin.ignore();

        switch (cmd) {
        case ADD: {
            school.InputAdd();
            break;
        }

        case SHOW20: {
            school.ShowAge20();
            break;
        }

        case SHOW23DN: {
            school.ShowAge23DaNang();
            break;
        }

        case QUIT: {
            cout << "Quitting..." << endl;
            break;
        }

        default: {
            cout << "Invalid command. Try again" << endl;
            break;
        }
        }
    }
}

int main()
{
    MainLoop();
    return 0;
}

