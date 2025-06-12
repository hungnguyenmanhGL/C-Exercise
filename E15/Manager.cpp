#include "Manager.h"
#include "Helper.h"

Manager::Manager() {
	facultyList.push_back(Faculty("Pratical Mathematics"));
	facultyList.push_back(Faculty("Computer Science"));
	facultyList.push_back(Faculty("Business Administration"));
	facultyList.push_back(Faculty("History"));

	AddTestData();
}

void Manager::AddStudent(int facultyIndex, shared_ptr<Student> student) {
	if (facultyIndex < 0 || facultyIndex >= facultyList.size()) {
		cout << "Invalid faculty index " << facultyIndex << ". Abort.\n";
		return;
	}
	
	facultyList[facultyIndex].AddStudent(student);
	if (student->IsFullTime()) {
		printf("Added 1 new Full-time student to faculty %s.\n", facultyList[facultyIndex].GetName().c_str());
	}
	else {
		printf("Added 1 new Part-time student to faculty %s.\n", facultyList[facultyIndex].GetName().c_str());
	}
}

void Manager::AddStudentByInput() {
	int index = 0;
	cout << "Input faculty. Check list below.\n";
	PrintFacultyIndexPrompt();
	cout << "Input value: ";
	cin >> index;
	cin.ignore();
	if (index < 0 || index >= facultyList.size()) {
		cout << "Quit adding student. Return to main.\n";
		return;
	}

	int type = 0;
	cout << "Input student type (0 = full-time, 1 = part-time, others = quit): ";
	cin >> type;
	cin.ignore();

	if (type != 0 && type != 1) {
		cout << "Quit adding student. Return to main.\n";
		return;
	}
	else {
		string id;
		cout << "Input id: ";
		getline(cin, id);

		string name = Helper::GetFullNameByInput();

		Date dob = Helper::GetDateByInput();

		cout << "Enroll year. ";
		int enrollYear = Helper::GetIntByInput(smallestEnrollYear);

		cout << "Entry score. ";
		int entryScore = Helper::GetIntByInput(0, 10);

		vector<StudyResult> resList;
		cout << "List of study results. ";
		int len = Helper::GetIntByInput(0);
		for (int i = 0; i < len; i++) {
			cout << "Semester. ";
			int semester = Helper::GetIntByInput(0);
			cout << "Average score. ";
			float avg = Helper::GetFloatByInput(0.00f, 10.00f);

			resList.push_back(StudyResult(semester, avg));
		}

		if (type == 0) {
			AddStudent(index, shared_ptr<Student>(new FullStudent(id, name, dob, enrollYear, entryScore, resList)));
			cout << "Back to main.\n";
		}
		else {
			string city;
			cout << "Input city: ";
			getline(cin, city);
			AddStudent(index, shared_ptr<Student>(new PartStudent(id, name, dob, enrollYear, entryScore, resList, city)));
			cout << "Back to main.\n";
		}
	}
}

void Manager::AddFaculty(const string& name) {
	for (Faculty& fa : facultyList) {
		if (fa.GetName()._Equal(name)) {
			cout << "Faculty " << name << " already exists. Abort.\n";
			return;
		}
	}
	facultyList.push_back(Faculty(name));
	cout << "Added faculty " << name << endl;
}

void Manager::PrintFacultyIndexPrompt() {
	cout << "Faculty index:\n";
	for (int i = 0; i < facultyList.size(); i++) {
		printf(" %d = %s\n", i, facultyList[i].GetName().c_str());
	}
	cout << " others = quit\n";
}

void Manager::ShowAll() {
	for (Faculty& fa : facultyList) {
		fa.ShowOrderedInfo();
		cout << "End of list.\n";
	}
}

void Manager::ShowFullCountFaculty() {
	int index = Helper::GetIntByInput(0, facultyList.size() - 1);
	facultyList[index].PrintName();
	cout << facultyList[index].GetFullTimeCount() << endl;
}

void Manager::ShowStudentsWithHighestEntry() {
	for (Faculty& fa : facultyList) {
		fa.PrintName();
		shared_ptr<Student> temp = fa.GetHighestEntryScoreStudent();
		if (temp != nullptr) temp->ShowInfo();
	}
}

void Manager::ShowPartStudentsFromCity(const string& city) {
	for (Faculty& fa : facultyList) {
		fa.PrintName();
		for (shared_ptr<Student>& s : fa.GetPartStudentListFromCity(city)) {
			s->ShowInfo();
		}
	}
}

void Manager::ShowStudentsWithLastSemesterAboveEight() {
	for (Faculty& fa : facultyList) {
		fa.PrintName();
		for (shared_ptr<Student>& s : fa.GetStudentListWithLastSemesterScoreAbove()) {
			s->ShowInfo();
			s->ShowStudyResults();
		}
	}
}

void Manager::ShowStudentsWithHighestSemesterScore() {
	for (Faculty& fa : facultyList) {
		fa.PrintName();
		shared_ptr<Student> temp = fa.GetStudentWithHighestSemesterScore();
		if (temp != nullptr) {
			temp->ShowInfo();
			temp->ShowStudyResults();
		}
	}
}

void Manager::ShowEnrollCountInYear(const int& year) {
	for (Faculty& fa : facultyList) {
		fa.PrintName();
		cout << fa.GetStudentCountByEnrollYear(year) << endl;
	}
}

void Manager::AddTestData() {
	mt19937 gen(static_cast<unsigned int>(time(nullptr)));
	for (int i = 0; i < 25; i++) {
		int faculty = Helper::GenRandomInt(gen, 0, facultyList.size() - 1);
		string id = Helper::GenRandomId(gen);
		string name = Helper::GenRandomName(gen);
		Date dob = Helper::GenRandomDob(gen);
		int enrollYear = Helper::GenRandomInt(gen, smallestEnrollYear, 2020);
		int entryScore = Helper::GenRandomInt(gen, 6, 10);
		vector<StudyResult> resList = Helper::GenRandomStudyResults(gen);

		int type = Helper::GenRandomInt(gen, 0, 1);
		if (type == 0) {
			AddStudent(faculty, shared_ptr<Student>(new FullStudent(id, name, dob, enrollYear, entryScore, resList)));
		}
		else {
			string city = Helper::GenRandomCity(gen);
			AddStudent(faculty, shared_ptr<Student>(new PartStudent(id, name, dob, enrollYear, entryScore, resList, city)));
		}
	}
}