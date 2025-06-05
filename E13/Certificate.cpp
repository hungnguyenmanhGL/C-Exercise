#include "Certificate.h"
#include <stdio.h>

Certificate::Certificate(string id, string name, int rank, Date date)
	: id(id), name(name), rank(rank), date(date) { }

void Certificate::ShowInfo() {
	printf("Certificate info: \n"
		" Id: %s\n"
		" Name: %s\n"
		" Rank: %d\n"
		" Date: %s\n",
		id.c_str(), name.c_str(), rank, date.ToString().c_str());
}