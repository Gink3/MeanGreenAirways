#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include"crew.h"

using namespace std;

void Crew::SetName(string n) {
    Name = n;
}

void Crew::SetID(int id) {
  IDNum = id;
}

void Crew::SetStatus(string s) {
  Status = s;
}
void Crew::SetStatus(int n) {
	switch(n) {
		case 0:
			Status="Available";
			break;
		case 1:
			Status="On Leave";
			break;
		case 2:
			Status="Sick";
			break;
	}
}

string Crew::GetName() {
  return Name;
}

int Crew::GetID() {
  return IDNum;
}

string Crew::GetStatus() {
  return Status;
}
int Crew::GetStatusInt() {
	if(Status == "Available") {
		return 0;
	} else if(Status == "On Leave") {
		return 1;
	} else if (Status == "Sick") {
		return 2;
	} else {
		return -1;
	}
}

void Crew::PrintInfo(){
	cout<<"Name: "<<Name<<endl;
	cout<<"ID Number: "<<IDNum<<endl;
	cout<<"Status: "<<Status<<endl;

}
void Crew::SaveInfo(ofstream &fout) {

	fout<<GetName()<<endl;
	fout<<GetID()<<endl;
	fout<<GetStatusInt()<<endl;

}
string Crew::GetCrewType() {
	return "Crew";
}