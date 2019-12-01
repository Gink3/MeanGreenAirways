#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"crews.h"
using namespace std;

//adds a crew obj to the CrewList vector
//given input from user
void Crews::AddCrew(){

	string name, status;
	int type, id;

	cout<<"Enter Crew type: "<<endl;
	cout<<"1 - Pilot"<<endl;
	cout<<"2 - Copilot"<<endl;
	cout<<"3 - Cabin"<<endl;

	
	do {
		cout<<"--------------------------------------"<<endl;
		cout<<"| Enter Crew Type                    |"<<endl;
		cout<<"--------------------------------------"<<endl;
		cout<<"|                                    |"<<endl;
		cout<<"| 0 - Pilot                          |"<<endl;
		cout<<"| 1 - Copilot                        |"<<endl;
		cout<<"| 2 - Cabin                          |"<<endl;
		cout<<"|                                    |"<<endl;
		cout<<"--------------------------------------"<<endl;
		cin>>type;
	} while(type < 0 || type > 2);


	cout<<"Enter Name: ";
	cin>>name;
	cout<<"Enter ID: ";
	cin>>id;
	cout<<"Enter Status: ";
	cin>>status;


	switch(type) {
		case 0: {
			Pilot *temp;
			string Rating;
			int flightHours;
			do {
				cout<<"Enter 5 character Rating: ";
				cin>>Rating;
			} while(Rating.length() != 5);

			cout<<"Enter flight hours: ";
			cin>>flightHours;

			temp->SetName(name);
			temp->SetID(id);
			temp->SetStatus(status);
			temp->SetRating(Rating);
			temp->SetHours(flightHours);

			CrewList.push_back(temp);

			break;
		}
		case 1: {
			Copilot *temp;
			string Rating;
			int flightHours;
			do {
				cout<<"Enter 4 character Rating: ";
				cin>>Rating;
			} while(Rating.length() != 4);

			cout<<"Enter flight hours: ";
			cin>>flightHours;

			temp->SetName(name);
			temp->SetID(id);
			temp->SetStatus(status);
			temp->SetRating(Rating);
			temp->SetHours(flightHours);

			CrewList.push_back(temp);

			break;
		}
		case 2: {
			Cabin *temp;
			int p;
			CabinPosition pos;

			do {
				cout<<"--------------------------------------"<<endl;
				cout<<"| Enter Crew Position                |"<<endl;
				cout<<"--------------------------------------"<<endl;
				cout<<"|                                    |"<<endl;
				cout<<"| 0 - First Class                    |"<<endl;
				cout<<"| 1 - Business Class                 |"<<endl;
				cout<<"| 2 - Economy Front                  |"<<endl;
				cout<<"| 3 - Economy Rear                   |"<<endl;
				cout<<"| 4 - Lead                           |"<<endl;
				cout<<"--------------------------------------"<<endl;
				cin>>p;
			} while (p > 4 || p < 0);
			pos=static_cast<CabinPosition>(p);

			temp->SetName(name);
			temp->SetID(id);
			temp->SetStatus(status);
			temp->SetPosition(pos);

			CrewList.push_back(temp);

			break;
		}
	}

	

}

//adds crew obj to CrewList Vector
//given already made obj
void Crews::AddCrew(Crew *c) {
	CrewList.push_back(c);
}

void Crews::EditCrew() {
	
	int id, status, flightHours, p;
	int choice, index, c=2;
	string type, name, rating;

	cout<<"Please Enter Crew Id"<<endl;
	cin >> id;

	index = FindCrew(id);
	if (index == -1) {
		return;
	}
	CrewList[index]->PrintInfo();
	type = CrewList[index]->GetCrewType();

	do {
		cout<<"--------------------------------------"<<endl;
		cout<<"| Enter Attribute to edit            |"<<endl;
		cout<<"--------------------------------------"<<endl;
		cout<<"|                                    |"<<endl;
		cout<<"| 0 - Name                           |"<<endl;
		cout<<"| 1 - ID                             |"<<endl;
		cout<<"| 2 - Status                         |"<<endl;
		
		

		if(type=="Pilot" || type=="Copilot") {
			cout<<"| 3 - Rating                         |"<<endl;
			cout<<"| 4 - Flight Hours                   |"<<endl;
			cout<<"|                                    |"<<endl;
			cout<<"--------------------------------------"<<endl;
			c=4;
		} else if (type=="Cabin") {
			cout<<"| 3 - Position                       |"<<endl;
			cout<<"|                                    |"<<endl;
			cout<<"--------------------------------------"<<endl;
			c=3;
		}
	} while(choice < 0 || choice > c);

	if(c > 2) {
		if(type=="Pilot") {
			
			if (c == 3) {
				do {
					cout<<"Enter 5 character Rating: ";
					cin>>rating;
					CrewList[index]->SetRating(rating);
					cout<<"Rating Set"<<endl;
				} while(rating.length() != 5);
			} else if (c == 4) {
				cout<<"Enter flight hours: ";
				cin>>flightHours;
				CrewList[index]->SetHours(flightHours);
				cout<<"Flight Hours Set"<<endl;
			} else {
				cout<<"Error choice = "<<c<<endl;
			}
		} else if (type=="Copilot") {
			if(c==3) {
				do {
					cout<<"Enter 4 character Rating: ";
					cin>>rating;
					CrewList[index]->SetRating(rating);
					cout<<"Rating Set"<<endl;
				} while(rating.length() != 4);
			} else if (c == 4) {
				cout<<"Enter flight hours: ";
				cin>>flightHours;
				CrewList[index]->SetHours(flightHours);
				cout<<"Flight Hours Set"<<endl;
			} else {
				cout<<"Error choice = "<<c<<endl;
			}
		} else if (type =="Cabin") {
			do {
				cout<<"--------------------------------------"<<endl;
				cout<<"| Enter Crew Position                |"<<endl;
				cout<<"--------------------------------------"<<endl;
				cout<<"|                                    |"<<endl;
				cout<<"| 0 - First Class                    |"<<endl;
				cout<<"| 1 - Business Class                 |"<<endl;
				cout<<"| 2 - Economy Front                  |"<<endl;
				cout<<"| 3 - Economy Rear                   |"<<endl;
				cout<<"| 4 - Lead                           |"<<endl;
				cout<<"--------------------------------------"<<endl;
				cin>>p;
			} while (p > 4 || p < 0);
			CrewList[index]->SetPosition(p);
			cout<<"Position Set"<<endl;
		}
	} else {
		switch(c) {
			case 0: {
				cout<<"Enter Name: ";
				cin>>name;
				CrewList[index]->SetName(name);
				cout<<"Name Set"<<endl;
			}
			case 1: {
				cout<<"Enter ID: ";
				cin>>id;
				CrewList[index]->SetID(id);
				cout<<"ID set"<<endl;
			}
			case 2: {
				do {
					cout<<"--------------------------------------"<<endl;
					cout<<"| Select Status                      |"<<endl;
					cout<<"--------------------------------------"<<endl;
					cout<<"|                                    |"<<endl;
					cout<<"| 0 - Available                      |"<<endl;
					cout<<"| 1 - On Leave                       |"<<endl;
					cout<<"| 2 - Sick                           |"<<endl;
					cout<<"|                                    |"<<endl;
					cout<<"--------------------------------------"<<endl;
					cin>>status;
					CrewList[index]->SetStatus(status);
				} while (status > 2 || status < 0);
				
			} 
		}
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

		CrewList[i]->SaveInfo(fout);
		

	}
	fout.close();
}

void Crews::LoadCrew() {

	int size, CrewID, CrewStatus;
	string CrewType, CrewName;

	ifstream fin;
	fin.open("crew.data");
	fin>>size;

	for(int i=0;i<size;i++){
		fin>>CrewType>>CrewName>>CrewID>>CrewStatus;
		

		if(CrewType=="pilot") {
			Pilot *temp;
			string Rating;
			int flightHours;
			fin>>Rating>>flightHours;

			temp->SetName(CrewName);
			temp->SetID(CrewID);
			temp->SetStatus(CrewStatus);
			temp->SetRating(Rating);
			temp->SetHours(flightHours);

			CrewList.push_back(temp);
		} else if (CrewType=="copilot") {
			Copilot *temp;
			string Rating;
			int flightHours;
			fin>>Rating>>flightHours;

			temp->SetName(CrewName);
			temp->SetID(CrewID);
			temp->SetStatus(CrewStatus);
			temp->SetRating(Rating);
			temp->SetHours(flightHours);

			CrewList.push_back(temp);
		} else if (CrewType=="cabin") {
			Cabin *temp;
			int p;
			CabinPosition Pos;
			
			fin>>p;
			Pos=static_cast<CabinPosition>(p);

			temp->SetName(CrewName);
			temp->SetID(CrewID);
			temp->SetStatus(CrewStatus);
			temp->SetPosition(Pos);

			CrewList.push_back(temp);
		} else {
			cout<<"Error: Invalid Crew Type"<<endl;
		}
		

	}

	fin.close();
	cout<<"Crew Loaded"<<endl;
}



