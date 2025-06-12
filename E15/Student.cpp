#include "Student.h"

Student::Student(string id, string name, Date dob, int enrollYear, int entryScore, vector<StudyResult>& resList)
	: id(id), name(name), dob(dob), enrollYear(enrollYear), entryScore(entryScore), resultList(resList)
{}

Student::Student(Student& s) {
	this->id = s.id;
	this->name = s.name;
	this->dob = s.dob;
	this->enrollYear = s.enrollYear;
	this->entryScore = s.entryScore;
	this->resultList = move(s.resultList);
	this->isFullTime = s.isFullTime;
}

void Student::ShowInfo() {
	printf("Id: %s\n"
		" Name: %s\n"
		" Date of birth: %s\n"
		" Enroll year: %d\n"
		" Entry score: %d\n",
		id.c_str(), name.c_str(), dob.ToString().c_str(), enrollYear, entryScore);
	if (isFullTime) { cout << " Type: Full-time\n"; }
	else { cout << " Type: Part-time\n"; }
}

void Student::ShowStudyResults() {
	for (StudyResult& res : resultList) {
		res.Print();
	}
}

bool Student::IsLastSemesterScoreAbove(float score) {
	StudyResult res = resultList[0];
	for (int i = 1; i < resultList.size(); i++) {
		if (res.GetSemester() < resultList[i].GetSemester())
			res = resultList[i];
	}
	return res.GetAvgScore() >= score;
}

float Student::GetHighestSemesterScore() {
	float res = resultList[0].GetAvgScore();
	for (int i = 1; i < resultList.size(); i++) {
		if (resultList[i].GetAvgScore() > res)
			res = resultList[i].GetAvgScore();
	}
	return res;
}