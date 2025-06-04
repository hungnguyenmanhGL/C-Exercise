#include "Student.h"
#include <stdio.h>

void Student::ShowInfo() {
	printf("ID: %s\n Name: %s\n Address: %s\n Priority: %d\n Block: %c\n",
		id.c_str(), name.c_str(), address.c_str(), priority, block);
	printf("Block %c' s subjects: %s, %s, %s\n",
		block, blockMap.at(block)[0].c_str(), blockMap.at(block)[1].c_str(), blockMap.at(block)[2].c_str());
}

bool Student::IsValidBlock(const char block) {
	return blockMap.find(block) != blockMap.end();
}

Student::Student(string id, string name, string address, int priority, char block)
	: id(id), name(name), address(address), priority(priority), block(block) {
	if (blockMap.find(block) == blockMap.end()) {
		printf("Block %c doesn't exist. Default to block A.", block);
		this->block = 'A';
	}
}

string Student::GetId() const {
	return this->id;
}

Student::Student() {}

Student::~Student() {}
