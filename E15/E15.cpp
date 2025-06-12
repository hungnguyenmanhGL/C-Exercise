#include <iostream>
#include "Manager.h"
#include "Helper.h"

void MainLoop() {
    Manager manager;
    int cmd;

    do {
        cout << "Command list:\n";
        Helper::PrintCommandList();
        cout << "Input command: ";
        cin >> cmd;
        cin.ignore();

        switch (cmd) {
        case Command::QUIT:
            cout << "Quitting\n";
            return;

        case Command::ADD_STUDENT:
            manager.AddStudentByInput();
            break;
            
        case Command::ADD_FACULTY: {
            string faculty;
            cout << "Input faculty name: ";
            getline(cin, faculty);
            manager.AddFaculty(faculty);
            break;
        }
        case Command::SHOW_ALL: {
            manager.ShowAll();
            break;
        }
        case Command::SHOW_FULL_COUNT_FACULTY: {
            manager.ShowFullCountFaculty();
            break;
        }
        case Command::GET_HIGHEST_ENTRY_FACULTY: {
            manager.ShowStudentsWithHighestEntry();
            break;

        }
        case Command::SHOW_PART_CITY: {
            string city;
            cout << "Input city: ";
            getline(cin, city);
            manager.ShowPartStudentsFromCity(city);
            break;
        }
        case Command::GET_STUDENTS_WITH_LAST_SEMESTER_SCORE: {
            manager.ShowStudentsWithLastSemesterAboveEight();
            break;
        }
        case Command::GET_STUDENT_WITH_HIGHEST_SEMESTER_SCORE: {
            manager.ShowStudentsWithHighestSemesterScore();
            break;
        }
        case Command::GET_ENROLL_COUNT_IN_YEAR: {
            int year = Helper::GetIntByInput(smallestEnrollYear);
            manager.ShowEnrollCountInYear(year);
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
    MainLoop();
    return 0;
}