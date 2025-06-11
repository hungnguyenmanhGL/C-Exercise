#include "Manager.h"
#include "FullNameException.h"
#include "EmailException.h"
#include "PhoneException.h"
#include "GoodStudent.h"
#include "NormalStudent.h"
#include <queue>

struct GradeComparator {
	bool operator()(shared_ptr<Student>& a, shared_ptr<Student>& b) {
		if (a->IsGood() && !b->IsGood())
			return false;
		else if (!a->IsGood() && b->IsGood())
			return true;

		if (a->IsGood() && b->IsGood()) {
			shared_ptr<GoodStudent> goodA = dynamic_pointer_cast<GoodStudent>(a);
			shared_ptr<GoodStudent> goodB = dynamic_pointer_cast<GoodStudent>(b);
			if (goodA->GetGpa() != goodB->GetGpa()) return goodA->GetGpa() < goodB->GetGpa();
			else return goodA->GetFullName() > b->GetFullName();
		}
		if (!a->IsGood() && !b->IsGood()) {
			shared_ptr<NormalStudent> normalA = dynamic_pointer_cast<NormalStudent>(a);
			shared_ptr<NormalStudent> normalB = dynamic_pointer_cast<NormalStudent>(b);
			if (normalA->GetEntryScore() != normalB->GetEntryScore()) return normalA->GetEntryScore() < normalB->GetEntryScore();
			else {
				if (normalA->GetEnglishScore() != normalB->GetEnglishScore()) return normalA->GetEnglishScore() < normalB->GetEnglishScore();
				else return normalA->GetFullName() > normalB->GetFullName();
			}
		}
		return false;
	}
};

struct DataComparator {
	bool operator()(shared_ptr<Student>& a, shared_ptr<Student>& b) {
		if (a->GetFullName()._Equal(b->GetFullName())) //if same name, compare by phone number
			return a->GetPhone() > b->GetPhone();
		else 
			return a->GetFullName() < b->GetFullName();
	}
};

void Manager::ReadFromFile(const string& path) {
	ifstream inputFile(path);
	if (!inputFile.is_open()) {
		cout << "Failed to open file " << path << ". Quitting." << endl;
		return;
	}

	string line;
	string name;
	Date dob;
	Gender gender;
	string phone, university;
	int gradeLevel;
	float gpa;
	string bestReward;
	int toeic, entryScore;

	while (getline(inputFile, line)) {
		if (line.rfind(dataTagMap.at(FULL_NAME), 0) == 0) {
			name = line.substr(dataTagMap.at(FULL_NAME).length());
			name = Helper::RemoveSpacesAtEnds(name);
			try {
				Helper::IsFullNameValid(name);
			}
			catch (const FullNameException& nameExcept) {
				cout << nameExcept.what();
				return;
			}
		}

		if (line.rfind(dataTagMap.at(DOB), 0) == 0) {
			string strDate = line.substr(dataTagMap.at(DOB).length());
			strDate = Helper::RemoveSpacesAtEnds(strDate);
			try {
				bool isDateFormat = Helper::IsDateFormat(strDate);
				if (!isDateFormat) throw DateException("Input string is not in dd/mm/yyyy format. Quit.");
			}
			catch (const DateException& dateExcept) {
				cout << dateExcept.what();
				return;
			}
			dob = Helper::GetDateByString(strDate);
		}

		if (line.rfind(dataTagMap.at(GENDER), 0) == 0) {
			string str = line.substr(dataTagMap.at(GENDER).length());
			str = Helper::RemoveSpacesAtEnds(str);
			int temp = atoi(str.c_str());
			if (temp < Gender::MALE && temp > Gender::OTHERS) {
				cout << "Invalid input for gender. Quit\n";
				return;
			}
			gender = (Gender)temp;
		}

		if (line.rfind(dataTagMap.at(PHONE), 0) == 0) {
			phone = line.substr(dataTagMap.at(PHONE).length());
			Helper::RemoveSpacesAtEnds(phone);
			try {
				bool isValid = Helper::IsPhoneValid(phone);
				if (!isValid) throw PhoneException("Invalid input phone number. Quit\n");
			}
			catch (const PhoneException& phoneExcept) {
				cout << phoneExcept.what();
				return;
			}
		}

		if (line.rfind(dataTagMap.at(UNIVERSITY), 0) == 0) {
			university = line.substr(dataTagMap.at(UNIVERSITY).length());
			Helper::RemoveSpacesAtEnds(university);
		}

		if (line.rfind(dataTagMap.at(GRADE_LEVEL), 0) == 0) {
			string str = line.substr(dataTagMap.at(GRADE_LEVEL).length());
			Helper::RemoveSpacesAtEnds(str);
			gradeLevel = atoi(str.c_str());
			if (gradeLevel < 0) {
				cout << "Invalid input grade level. Quit.\n";
				return;
			}
		}

		if (line.rfind(dataTagMap.at(GPA), 0) == 0) {
			string str = line.substr(dataTagMap.at(GPA).length());
			Helper::RemoveSpacesAtEnds(str);
			gpa = stof(str.c_str());
			if (gpa < 0) {
				cout << "Invalid input for GPA. Quit\n";
				return;
			}
		}

		if (line.rfind(dataTagMap.at(BEST_REWARD), 0) == 0) {
			bestReward = line.substr(dataTagMap.at(BEST_REWARD).length());
			bestReward = Helper::RemoveSpacesAtEnds(bestReward);

			shared_ptr<GoodStudent> stu(new GoodStudent(name, dob, gender, phone, university, gradeLevel, gpa, bestReward));
			goodList.push_back(stu);
		}

		if (line.rfind(dataTagMap.at(ENGLISH_SCORE), 0) == 0) {
			string str = line.substr(dataTagMap.at(ENGLISH_SCORE).length());
			Helper::RemoveSpacesAtEnds(str);
			toeic = atoi(str.c_str());
			if (toeic < 0 || toeic > 990) {
				cout << "Invalid input TOEIC score. Quit.\n";
				return;
			}
		}

		if (line.rfind(dataTagMap.at(ENTRY_SCORE), 0) == 0) {
			string str = line.substr(dataTagMap.at(ENTRY_SCORE).length());
			Helper::RemoveSpacesAtEnds(str);
			entryScore = atoi(str.c_str());
			if (entryScore < 0 || entryScore > 10) {
				cout << "Invalid input entry score. Quit.\n";
				return;
			}

			shared_ptr<NormalStudent> stu(new NormalStudent(name, dob, gender, phone, university, gradeLevel, toeic, entryScore));
			normalList.push_back(stu);
		}
	}

	inputFile.close();

	printf("Input reading completed. Added %d good and %d normal students. Total %d.\n", 
		goodList.size(), normalList.size(), goodList.size() + normalList.size());
	//ShowAll();
}

void Manager::ShowAll() {
	for (shared_ptr<GoodStudent>& s : goodList) s->ShowInfo();
	cout << "End of Good list.\n" << endl;

	for (shared_ptr<NormalStudent>& s : normalList) s->ShowInfo();
	cout << "End of Normal list.\n" << endl;
}

void Manager::ShowAllContactData() {
	priority_queue<shared_ptr<Student>, vector<shared_ptr<Student>>, DataComparator> q;
	for (shared_ptr<GoodStudent>& s : goodList) q.push(s);
	for (shared_ptr<NormalStudent>& s : normalList) q.push(s);

	while (!q.empty()) {
		q.top()->ShowInfo();
		q.pop();
	}
	cout << "End of list\n";
}

vector<shared_ptr<Student>> Manager::GetCandidateList(int num) {
	int goodCnt = goodList.size();
	int normalCnt = normalList.size();
	if (num > goodCnt + normalCnt) {
		printf("Requested number %d > total student count %d. Get all students.\n", num, goodCnt + normalCnt);
		num = goodCnt + normalCnt;
	}

	vector<shared_ptr<Student>> res;
	priority_queue<shared_ptr<Student>, vector<shared_ptr<Student>>, GradeComparator> q;
	//get all good students ordered by custom comparator
	for (shared_ptr<GoodStudent>& s : goodList) {
		q.push(s);
	}

	if (num <= goodCnt) {
		for (int i = 0; i < num; i++) {
			res.push_back(q.top());
			q.pop();
		}
	}
	else {
		for (shared_ptr<NormalStudent>& s : normalList) {
			q.push(s);
		}
		for (int i = 0; i < num; i++) {
			res.push_back(q.top());
			q.pop();
		}
	}

	cout << "All suitable candidates found:\n" << endl;
	for (int i = 0; i < num; i++) {
		res[i]->ShowInfo();
	} cout << "End of list.\n" << endl;

	return res;
}