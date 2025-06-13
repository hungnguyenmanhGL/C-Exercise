#include "Faculty.h"
#include <queue>
Faculty::Faculty(string name) : name(name) {
}

void Faculty::PrintName() { cout << "Faculty - " << name << ":\n"; }

int Faculty::GetFullTimeCount() {
	int cnt = 0;
	for (shared_ptr<Student>& s : studentList) {
		if (s->IsFullTime()) cnt++;
	}
	return cnt;
}

shared_ptr<Student> Faculty::GetHighestEntryScoreStudent() {
	if (studentList.size() == 0) {
		cout << "0 student data.\n";
		return nullptr;
	}

	int index = 0;
	for (int i = 0; i < studentList.size(); i++) {
		if (studentList[i]->GetEntryScore() > studentList[index]->GetEntryScore())
			index = i;
	}
	return studentList[index];
}

vector<shared_ptr<Student>> Faculty::GetPartStudentListFromCity(const string& city) {
	vector<shared_ptr<Student>> res;
	for (shared_ptr<Student>& s : studentList) {
		if (!s->IsFullTime()) {
			shared_ptr<PartStudent> temp = dynamic_pointer_cast<PartStudent>(s);
			if (temp->GetCity()._Equal(city)) res.push_back(temp);
		}
	}
	return res;
}

vector<shared_ptr<Student>> Faculty::GetStudentListWithLastSemesterScoreAbove() {
	vector<shared_ptr<Student>> res;
	for (shared_ptr<Student>& s : studentList) {
		if (s->IsLastSemesterScoreAbove(8.0f)) {
			res.push_back(s);
		}
	}
	return res;
}

shared_ptr<Student> Faculty::GetStudentWithHighestSemesterScore() {
	if (studentList.size() == 0) {
		cout << "0 student data.\n";
		return nullptr;
	}

	shared_ptr<Student>& res = studentList[0];
	for (shared_ptr<Student>& s : studentList) {
		if (s->GetHighestSemesterScore() > res->GetHighestSemesterScore()) {
			res = s;
		}
	}
	return res;
}

int Faculty::GetStudentCountByEnrollYear(const int& year) {
	int cnt = 0;
	for (shared_ptr<Student>& s : studentList) {
		if (s->GetEnrollYear() == year) cnt++;
	}
	return cnt;
}

void Faculty::ShowOrderedInfo() {
	PrintName();
	if (studentList.size() == 0) {
		cout << "0 student data.\n";
		return;
	}

	priority_queue<shared_ptr<Student>, vector<shared_ptr<Student>>, StudentComparator> q;
	for (shared_ptr<Student>& s : studentList) q.push(s);
	while (!q.empty()) {
		q.top()->ShowInfo();
		q.top()->ShowStudyResults();
		q.pop();
	}
}

void Faculty::AddStudent(shared_ptr<Student>& student) {
	studentList.push_back(student);
}