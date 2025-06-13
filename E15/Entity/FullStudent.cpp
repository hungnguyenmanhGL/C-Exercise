#include "FullStudent.h"

FullStudent::FullStudent() {
    this->isFullTime = true;
}

FullStudent::FullStudent(string id, string name, Date dob, int enrollYear, int entryScore, vector<StudyResult>& resList)
    : Student(id, name, dob, enrollYear, entryScore, resList) {
    this->isFullTime = true;
}