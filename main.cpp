#include <iostream>
#include "hms.h"
#include <string>

using namespace std;

int main() {
	int choice;
	string name;
	int patientid;
	
	hms L;
	L.start=NULL;
	while(1)
	{
		cout<<"1. Add a Patient"<<endl;
		cout<<"2. Remove a Patient"<<endl;
		cout<<"3. Display Admitted Patients"<<endl;
		cout<<"4. Search a Patient"<<endl;
		cout<<"5. Quit"<<endl;
		cout<<"Enter ur choice"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
					cout<<"Enter Patient Name "<<endl;
					cin>>name;
					cout<<"Enter Patient ID "<<endl;
					cin>>patientid;
					L.addpatient(name,patientid);
				
				break;
			case 2:
				if(L.start==NULL)
				{
					cout<<"List is empty"<<endl;
					continue;
				}
				cout<<"Enter Patient Name for Deletion"<<endl;
				cin>>name;
				L.delpatient(name);
				break;
			case 3:
				L.displaypatients();
				break;
			case 4:
				cout<<"Enter Patient Name "<<endl;
				cin>>name;
				L.searchpatient(name);
				break;
			case 5:
				exit(1);
			default:
				cout<<"Wrong choice"<<endl;
				exit(1);
		}
	}
}
