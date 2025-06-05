#include "Person.h"
#include <stdio.h>

Person::Person(string name, int age, string job, string id) 
	: name(name), age(age), job(job), id(id) { }

Person::~Person() {}

void Person::ShowInfo() {
	printf("Name: %s\n Age: %d\n Job: %s\n Id: %s\n",
		name.c_str(), age, job.c_str(), id.c_str());
}