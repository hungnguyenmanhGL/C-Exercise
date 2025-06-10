#pragma once
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include "Date.h"
using namespace std;

static enum Gender {
	MALE = 0,
	FEMALE = 1,
	OTHERS = 2
};

static const unordered_map<Gender, string> genderMap{
	{MALE, "Male"},
	{FEMALE, "Female"},
	{OTHERS, "Others"}
};

static enum Data {
	FULL_NAME = 0,
	DOB = 1,
	GENDER = 2,
	PHONE = 3,
	UNIVERSITY = 4,
	GRADE_LEVEL = 5,
	GPA = 6,
	BEST_REWARD = 7,
	ENGLISH_SCORE = 8,
	ENTRY_SCORE = 9
};

static const unordered_map<Data, string> dataTagMap{
	{FULL_NAME, "Full name: "},
	{DOB, "Date of birth: "},
	{GENDER, "Gender: "},
	{PHONE, "Phone: "},
	{UNIVERSITY, "University: "},
	{GRADE_LEVEL, "Grade level: "},
	{GPA, "GPA: "},
	{BEST_REWARD, "Best Reward: "},
	{ENGLISH_SCORE, "English score: "},
	{ENTRY_SCORE, "Entry score: "}
};

static enum Command {
	ADD = 0,
	SHOW = 1,
	SEARCH = 2,
	QUIT = -1
};

static enum SearchSubCommand {
	BACK = -1,
	EDIT = 0,
	SUB_DELETE = 1,
	SUB_ADD = 2
};

const unordered_set<string> phoneStarterSet{
	"090", "098", "091", "031", "035", "038"
};

const unordered_set<string> emailEndSet{
	".com", ".net", ".org"
};

const unordered_set<char> invalidCharSet{
	'/', ',', '[', ']', '(', ')', '{', '}', ':', ';', '|'
};

class Helper
{
public:
	static Date GetDateByInput();

	static Date GetDateByString(const string& s);

	static string GetFullNameByInput();

	static string GetPhoneByInput();

	static string GetEmailByInput();

	static string RemoveSpacesAtEnds(string& s);

	//Input lowerThan <= value <= biggerThan .If lowerThan < biggerThan -> no upper limit
	static int GetIntByInput(int biggerThan, int lowerThan = -1);

	static bool IsFullNameValid(const string& name);

	static bool IsDateValid(int day, int month, int year);

	static bool IsPhoneValid(const string& phone);

	static bool IsEmailValid(const string& email);

	static bool Is31DayMonth(int month);

	static bool IsDateFormat(const string& s);

	static bool IsStringInt(const string& s);
};

const string whiteSpaces = " \t\n\r\f\v";