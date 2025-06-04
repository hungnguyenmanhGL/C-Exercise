#include "StudentA.h"

StudentA::StudentA(string id, string name, string address, int priority) 
	: Student(id, name, address, priority) { }

StudentA::~StudentA() {}

void StudentA::ShowInfo() {
	Student::ShowInfo();
	printf("Student's block: %s, %s, %s\n",
		blockMap.at(blockA)[0].c_str(), blockMap.at(blockA)[1].c_str(), blockMap.at(blockC)[2].c_str());
}
