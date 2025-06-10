#include "GoodStudent.h"

GoodStudent::GoodStudent(string name, Date doB, Gender gender, string phone, string uni, int gradeLvl, float gpa, string bestReward)
	: Student(name, doB, gender, phone, uni, gradeLvl), gpa(gpa), bestReward(bestReward) { }

void GoodStudent::ShowInfo() {
	Student::ShowInfo();
	printf(" GPA: %.2f\n Best reward: %s\n", gpa, bestReward.c_str());
}