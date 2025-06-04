#include "StudentB.h"
StudentB::StudentB(string id, string name, string address, int priority)
	: Student(id, name, address, priority) {
}

StudentB::~StudentB() {}

void StudentB::ShowInfo() {
	Student::ShowInfo();
	printf("Student's block: %s, %s, %s\n",
		blockMap.at(blockB)[0].c_str(), blockMap.at(blockB)[1].c_str(), blockMap.at(blockB)[2].c_str());
}