#include "Household.h"
#include <iostream>
#include <stdio.h>
using namespace std;

Household::Household(int no) : no(no) {}

Household::~Household() {}

void Household::AddMember(Person& person) {
	memberList.push_back(person);
}

void Household::ShowInfo() {
	printf("House no. %d has %d member(s)\n", no, memberList.size());
	for (Person& p : memberList) {
		p.ShowInfo();
	}
	cout << endl;
}


