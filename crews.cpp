#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"crews.h"
using namespace std;

void Crews::AddCrew(){

	Crew c;
	int n;
	string s;

	cout<<"Enter Crew Name: ";
	cin>>s;
	c.SetName(s);

	cout<<"Enter ID Number: ";
	cin>>n;
	c.SetID(n);

	cout<<"Enter Type(Pilot/Cabin): ";
	cin>>s;
	c.SetType(s);

	CrewList.push_back(c);

}
void Crews::AddCrew(Crew c) {
	CrewList.push_back(c);
}

void Crews::EditCrew() {
	
	int id;
	int c;

	cout<<"Please Enter Crew Id"<<endl;
	cin >> id;

	//outputs member if found
	for(vector<Crew>::iterator it=CrewList.begin();it!=CrewList.end();++it) {
		
		if((*it).GetID() == id) {
			cout << "Crew Member: " << (*it).GetName() << endl;
			cout << "ID number: " << (*it).GetID() << endl;
			cout << "Type: " << (*it).GetType() << endl;
			cout << endl;
			break;
		}
	}


	//menu for element selection
	cout<<"--------------------------------------"<<endl;
	cout<<"| Please Select the element to Edit  |"<<endl;
	cout<<"--------------------------------------"<<endl;
	cout<<"|                                    |"<<endl;
	cout<<"| 0 - Name                           |"<<endl;
	cout<<"| 1 - ID Number                      |"<<endl;
	cout<<"| 2 - Type                           |"<<endl;
	cout<<"--------------------------------------"<<endl;

	cin>>c;
	string s;
	int Newid;
	if(c == 0) {

		
		cout<<"Please Enter a new name: "<<endl;
		CrewList[id].SetName(s);
		cout<<"New Name Set"<<endl;


	} else if (c == 1) {

		cout<<"Please Enter a new ID" << endl;
		cin>>Newid;
		CrewList[id].SetID(Newid);
		cout<<"New ID Set"<<endl;

	} else if (c == 2) {

		cout<<"Please Enter a new Type(Pilot/Cabin): "<<endl;
		cin>>s;
		CrewList[id].SetType(s);
		cout<<"New Type Set"<<endl;
	}


}
void Crews::DeleteCrew(){

	int n;
	cout<<"Enter Crew ID: ";
	cin>>n; 

	for(vector<Crew>::iterator it=CrewList.begin();it!=CrewList.end();++it) {
		if((*it).GetID() == n) {
			CrewList.erase(it);
			cout << "Crew Member Deleted" <<endl;
		} else {

			cout<<"Crew Member not found"<<endl;
		}
	}

}
void Crews::DeleteCrew(int id) {
	for(vector<Crew>::iterator it=CrewList.begin();it!=CrewList.end();++it) {
		if((*it).GetID() == id) {
			CrewList.erase(it);
			cout << "Crew Member Deleted" <<endl;
		} else {

			cout<<"Crew Member not found"<<endl;
		}
	}

}
int Crews::FindCrew(int id) {
	int index=0;
	for(vector<Crew>::iterator it=CrewList.begin();it!=CrewList.end();++it) {
		index+=1;
		if((*it).GetID() == id) {
			return index;
		}
	}
	cout<<"Crew Member not Found"<<endl;
	return -1;
}
void Crews::PrintAllCrew() {

	
	for(vector<Crew>::iterator it=CrewList.begin();it!=CrewList.end();++it) {
		
	cout << "Crew Member: " << (*it).GetName() << endl;
	cout << "ID number: " << (*it).GetID() << endl;
	cout << "Type: " << (*it).GetType() << endl;
	cout << endl;

	}
}
void Crews::PrintCrew() {

	int index,n;
	cout<<"Enter Crew Member ID: ";
	cin>>n;

	index=FindCrew(n);

	cout << "Crew Member: " << CrewList[index].GetName() << endl;
	cout << "ID number: " << CrewList[index].GetID() << endl;
	cout << "Type: " << CrewList[index].GetType() << endl;
	cout << endl;

}

void Crews::SaveCrew() {

	ofstream fout;
	fout.open("crew.data");
	fout<<CrewList.size()<<endl;

	for(int i=0;i<CrewList.size();i++) {

		fout<<CrewList[i].GetName()<<endl;
		fout<<CrewList[i].GetID()<<endl;
		fout<<CrewList[i].GetType()<<endl;

	}
	fout.close();
}

void Crews::LoadCrew() {

	int size;
	Crew MyCrew;
	string CrewName;
	int CrewID;
	string CrewType;

	ifstream fin;
	fin.open("crew.data");
	fin>>size;

	for(int i=0;i<size;i++){

		fin>>CrewName;
		fin>>CrewID;
		fin>>CrewType;

		MyCrew.SetName(CrewName);
		MyCrew.SetID(CrewID);
		MyCrew.SetType(CrewType);

		CrewList.push_back(MyCrew);

	}

	fin.close();
	cout<<"Crew Loaded"<<endl;
}


