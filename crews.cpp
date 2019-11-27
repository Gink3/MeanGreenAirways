#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"crews.h"
using namespace std;

//adds a crew obj to the CrewList vector
//given input from user
void Crews::AddCrew(){

	cout<<"Enter Crew type: "<<endl;
	cout<<"1 - Pilot"<<endl;
	cout<<"2 - Copilot"<<endl;
	cout<<"3 - Cabin"<<endl;

	



	//TODO finish add crew

}

//adds crew obj to CrewList Vector
//given already made obj
void Crews::AddCrew(Crew *c) {
	CrewList.push_back(c);
}

void Crews::EditCrew() {
	
	int id;
	int c, index=0;
	bool found = false;

	cout<<"Please Enter Crew Id"<<endl;
	cin >> id;

	//outputs member if found
	for(vector<Crew*>::iterator it=CrewList.begin();it!=CrewList.end();++it) {
		
		if((*it).GetID() == id) {
			found = true;
			cout << "Crew Member: " << (*it)->GetName() << endl;
			cout << "ID number: " << (*it)->GetID() << endl;
			cout << "Status: " << (*it)->GetStatus() << endl;
			cout << endl;

			break;
			
		}
		index +=1;
	}

	//checks to make sure crew member found
	if(!found) {

		cout<<"Crew Member not found"<<endl;
		return;
	}

	//menu for element selection
	cout<<"--------------------------------------"<<endl;
	cout<<"| Please Select the element to Edit  |"<<endl;
	cout<<"--------------------------------------"<<endl;
	cout<<"|                                    |"<<endl;
	cout<<"| 0 - Name                           |"<<endl;
	cout<<"| 1 - ID Number                      |"<<endl;
	cout<<"| 2 - Status                         |"<<endl;
	cout<<"--------------------------------------"<<endl;

	cout<<"Enter element: ";
	cin>>c;
	string s;
	int n;
	
	//checks for proper input
	while(c > 2 || c < 0) {
		cout<<"Invalid Choice"<<endl;
		cout<<"Enter choice: ";
		cin>>c;
	}


	if(c == 0) {

		
		cout<<"Please Enter a new name: "<<endl;
		cin>>s;
		CrewList[index]->SetName(s);
		cout<<"New Name Set"<<endl;


	} else if (c == 1) {

		cout<<"Please Enter a new ID" << endl;
		cin>>n;
		CrewList[index]->SetID(n);
		cout<<"New ID Set"<<endl;

	} else if (c == 2) {

		cout<<"Please Enter a new Status: "<<endl;
		cin>>s;
		CrewList[index]->SetStatus(s);
		cout<<"New Status Set"<<endl;
	}


}
void Crews::DeleteCrew(){

	int n;
	cout<<"Enter Crew ID: ";
	cin>>n; 

	for(vector<Crew*>::iterator it=CrewList.begin();it!=CrewList.end();++it) {
		if((*it)->GetID() == n) {
			CrewList.erase(it);
			cout << "Crew Member Deleted" <<endl;
		} else {

			cout<<"Crew Member not found"<<endl;
		}
	}

}
void Crews::DeleteCrew(int id) {

	for(vector<Crew*>::iterator it=CrewList.begin();it!=CrewList.end();++it) {
		if((*it)->GetID() == id) {
			CrewList.erase(it);
			cout << "Crew Member Deleted" <<endl;
		} else {

			cout<<"Crew Member not found"<<endl;
		}
	}

}
int Crews::FindCrew(int id) {
	int index=0;
	for(vector<Crew*>::iterator it=CrewList.begin();it!=CrewList.end();++it) {
		index+=1;
		if((*it)->GetID() == id) {
			return index;
		}
	}
	cout<<"Crew Member not Found"<<endl;
	return -1;
}
void Crews::PrintAllCrew() {

	
	for(vector<Crew*>::iterator it=CrewList.begin();it!=CrewList.end();++it) {
		
	cout << "Crew Member: " << (*it)->GetName() << endl;
	cout << "ID number: " << (*it)->GetID() << endl;
	cout << "Status: " << (*it)->GetStatus() << endl;
	cout << endl;

	}
}
void Crews::PrintCrew() {

	int index;
	int n;
	cout<<"Enter Crew Member ID: ";
	cin>>n;

	index=FindCrew(n);

	cout << "Crew Member: " << CrewList[index]->GetName() << endl;
	cout << "ID number: " << CrewList[index]->GetID() << endl;
	cout << "Status: " << CrewList[index]->GetStatus() << endl;
	cout << endl;

}

void Crews::SaveCrew() {

	ofstream fout;
	fout.open("crew.data");
	fout<<CrewList.size()<<endl;

	for(int i=0;i<CrewList.size();i++) {

		fout<<CrewList[i]->GetName()<<endl;
		fout<<CrewList[i]->GetID()<<endl;
		fout<<CrewList[i]->GetStatus()<<endl;
		
		

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
		MyCrew.SetStatus(CrewType);

		CrewList.push_back(MyCrew);

	}

	fin.close();
	cout<<"Crew Loaded"<<endl;
}



