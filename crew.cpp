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

string Crew::GetName() {
  return Name;
}

int Crew::GetID() {
  return IDNum;
}

string Crew::GetStatus() {
  return Status;
}

void Crew::PrintInfo(){
	cout<<"Name: "<<Name<<endl;
	cout<<"ID Number: "<<IDNum<<endl;
	cout<<"Status: "<<Status<<endl;

}
void Crew::Save() {

	ofstream fout;
	fout.open("crew.data");
	

	fout<<GetName()<<endl;
	fout<<GetID()<<endl;
	fout<<GetStatus()<<endl;
	


	fout.close();
	
}