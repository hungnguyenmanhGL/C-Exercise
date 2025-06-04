#include "StudentC.h"

StudentC::StudentC(string id, string name, string address, int priority)
	: Student(id, name, address, priority) {
}

StudentC::~StudentC() {}

void StudentC::ShowInfo() {
	Student::ShowInfo();
	printf("Student's block: %s, %s, %s\n",
		blockMap.at(blockC)[0].c_str(), blockMap.at(blockC)[1].c_str(), blockMap.at(blockC)[2].c_str());
}