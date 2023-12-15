#include "hms.h"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

	void hms :: addpatient(string name,int patientid){
			struct node *q, *temp;	
			temp=new(struct node);
			temp->name=name;
			temp->patientid=patientid;
			time_t now= time(0);
			temp->time= ctime(&now);
			temp->link=NULL;
			if(start==NULL)	{
				start=temp;
			}
			else{
				q=start;
				while(q->link!=NULL) {
					q=q->link;
				}
			q->link=temp;
			}
		}
			
	void hms :: displaypatients() {
		struct node *q;
		if(start==NULL) {
			cout<<"No Patients Admitted"<<endl;
			return;
		}
		else {
			q=start;
			cout<<"Admitted Patients :"<<endl;
			cout<<"ID\tNAME\tADMITTED TIME"<<endl;
			while(q!=NULL) {
				cout<<q->patientid<<"\t"<<q->name<<"\t"<<q->time<<endl;
				q=q->link;
			}
				cout<<endl;
			}
		}

void hms :: delpatient(string name){
	struct node *tmp,*q;
	if(start->name==name)
	{
		tmp=start;
		start=start->link;	/*first element deleted*/
		delete(tmp);
		return;
	}
	q=start;
	while(q->link->link!=NULL)
	{
		if(q->link->name==name)	       /*element deleted in between*/
		{
			tmp=q->link;
			q->link=tmp->link;
			free(tmp);
			return;
		}
		q=q->link;
	}
	if(q->link->name==name)		/*last element deleted*/
	{
		tmp=q->link;
		free(tmp);
		q->link=NULL;
		return;
	}
	cout<<"Patient "<<name<<" not found"<<endl;
}


void hms :: searchpatient(string name){
	struct node *q=start;
	while(q!=NULL)
	{
		if(q->name==name)
		{
			cout<<q->patientid<<"\t"<<q->name<<"\t"<<q->time<<endl;
			return;
		}
		q=q->link;
	}
	if(q==NULL)	
		cout<<"Patient "<<name<<" not Admitted in Hospital"<<endl;
	}
