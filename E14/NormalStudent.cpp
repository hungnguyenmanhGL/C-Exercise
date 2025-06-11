#include "NormalStudent.h"

NormalStudent::NormalStudent() {
	this->isGood = false;
}

NormalStudent::NormalStudent(string name, Date doB, Gender gender, string phone, string uni, int gradeLvl, int englishScore, int entryScore)
	: Student(name, doB, gender, phone, uni, gradeLvl), englishScore(englishScore), entryScore(entryScore) {
}

void NormalStudent::ShowInfo() {
	Student::ShowInfo();
	printf(" English score: %d\n Entry score: %d\n", englishScore, entryScore);
}
