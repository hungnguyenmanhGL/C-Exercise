#include "Manager.h"
#include "FullNameException.h"
#include "EmailException.h"
#include "PhoneException.h"
#include "GoodStudent.h"
#include "NormalStudent.h"

void Manager::ReadFromFile(const string& path) {
	ifstream inputFile(path);
	if (!inputFile.is_open()) {
		cout << "Failed to open file " << path << ". Quitting." << endl;
		return;
	}

	int goodCnt = 0, normalCnt = 0;
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
		//cout << line << endl;

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

			shared_ptr<Student> stu(new GoodStudent(name, dob, gender, phone, university, gradeLevel, gpa, bestReward));
			studentList.push_back(stu);
			goodCnt++;
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

			shared_ptr<Student> stu(new NormalStudent(name, dob, gender, phone, university, gradeLevel, toeic, entryScore));
			studentList.push_back(stu);
			normalCnt++;
		}
	}

	inputFile.close();

	printf("Input reading completed. Added %d good and %d normal students. Total %d.\n", 
		goodCnt, normalCnt, goodCnt + normalCnt);
	ShowAll();
}

void Manager::ShowAll() {
	for (shared_ptr<Student> s : studentList) s->ShowInfo();
	cout << "End of list\n";
}