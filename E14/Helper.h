#pragma once
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include "Date.h"
using namespace std;

static const enum Gender {
	MALE = 0,
	FEMALE = 1,
	OTHERS = 2
};

static unordered_map<Gender, string> genderMap{
	{MALE, "Male"},
	{FEMALE, "Female"},
	{OTHERS, "Others"}
};

static const enum Command {
	ADD = 0,
	SHOW = 1,
	SEARCH = 2,
	QUIT = -1
};

static const enum SearchSubCommand {
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

	static string GetFullNameByInput();

	static string GetPhoneByInput();

	static string GetEmailByInput();

	//Input lowerThan <= value <= biggerThan .If lowerThan < biggerThan -> no upper limit
	static int GetIntByInput(int biggerThan, int lowerThan = -1);

	static bool IsFullNameValid(const string& name);

	static bool IsDateValid(int day, int month, int year);

	static bool IsPhoneValid(const string& phone);

	static bool IsEmailValid(const string& email);

	static bool Is31DayMonth(int month);
};

