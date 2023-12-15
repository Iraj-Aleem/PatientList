#ifndef hms_H
#define hms_H
#include <iostream>
#include <string>
using namespace std;

struct node {
	string name,time;
	char *time1;
	int patientid;
	node *link;	//self referential pointer
};

struct hms{
	public:
		node *start=NULL;
	
		void addpatient(string,int);
		void displaypatients();
		void delpatient(string);
		void searchpatient(string);
};

#endif
