#include <iostream>
#include "Manager.h"

const string path = "Input/data.txt";

void MainLoop(Manager& manager) {
    int cmd = 0;
    do {
        printf("Input command (%d = get, %d = show all contacts, %d = quit): ",
            Command::GET, Command::SHOW_CONTACT_ALL, Command::QUIT);
        cin >> cmd;
        cin.ignore();

        switch (cmd)
        {
        case Command::GET: {
            cout << "Input number of students to get (value > 0): ";
            int num = Helper::GetIntByInput(1);
            manager.GetCandidateList(num);
            break;
        }
        case Command::SHOW_CONTACT_ALL: {
            manager.ShowAllContactData();
            break;
        }
        case Command::QUIT: {
            cout << "Quitting...\n";
            break;
        }
        default:
            cout << "Invalid command. Try again.\n";
            break;
        }
    } while (cmd != Command::QUIT);
}

int main()
{
    Manager manager;
    manager.ReadFromFile(path);
    MainLoop(manager);
    return 0;
}
