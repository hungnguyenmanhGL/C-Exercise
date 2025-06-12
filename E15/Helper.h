#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <random>
#include <ctime>
#include "Date.h"
#include "StudyResult.h"
using namespace std;

static enum Command {
	ADD_STUDENT = 0,
	ADD_FACULTY = 1,
	SHOW_ALL = 2,
	SHOW_FULL_COUNT_FACULTY = 3,
	GET_HIGHEST_ENTRY_FACULTY = 4,
	SHOW_PART_CITY = 5,
	GET_STUDENTS_WITH_LAST_SEMESTER_SCORE = 6,
	GET_STUDENT_WITH_HIGHEST_SEMESTER_SCORE = 7,
	GET_ENROLL_COUNT_IN_YEAR = 8,
	QUIT = -1
};

static unordered_map<Command, string> commandMap{
	{ADD_STUDENT, "add student"},
	{ADD_FACULTY, "add faculty"},
	{SHOW_ALL, "show all students (ordered)"},
	{SHOW_FULL_COUNT_FACULTY, "show full-time count in a faculty"},
	{GET_HIGHEST_ENTRY_FACULTY, "get highest entry score each faculty"},
	{SHOW_PART_CITY, "get part-time students from city \"city name\""},
	{GET_STUDENTS_WITH_LAST_SEMESTER_SCORE, "get students with last semester score > 8.0"},
	{GET_STUDENT_WITH_HIGHEST_SEMESTER_SCORE, "get students with highest semester score each faculty"},
	{GET_ENROLL_COUNT_IN_YEAR, "get enroll number for every faculty in year yyyy"},
	{QUIT, "quit"}
};

static const int smallestEnrollYear = 2000;

class Helper
{
public:
	static Date GetDateByInput();

	static string GetFullNameByInput();

	//Input biggerThan <= value <= lowerThan .If lowerThan < biggerThan -> no upper limit
	static int GetIntByInput(int biggerThan, int lowerThan = -1);

	static float GetFloatByInput(float biggerThan, float lowerThan = -1);

	static bool IsFullNameValid(const string& name);

	static bool IsDateValid(int day, int month, int year);

	static bool Is31DayMonth(int month);

	static void PrintCommandList();

	//random data for test
	static string GenRandomId(mt19937& gen);

	static string GenRandomName(mt19937& gen);

	static Date GenRandomDob(mt19937& gen);

	static vector<StudyResult> GenRandomStudyResults(mt19937& gen);

	static string GenRandomCity(mt19937& gen);

	static int GenRandomInt(mt19937& gen, int biggerThan, int smallerThan);
};