#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"planes.h"
#include"flights.h"
using namespace std;

void Flights::AddFlight() {

	Flight MyFlight;

	string Tail;
	int NumP;
	int NumC;
	vector<int> PilotID;
	vector<int> CrewID;
	string StartTime;
	string EndTime;
	string StartCode;
	string EndCode;
	int NumPass;
	string fStatus;

	cout<<"Enter Tail Numeber: ";
	cin>>Tail;
	


	cout<<"Enter Number of Pilots: ";
	cin>>NumP;

	cout<<"Enter Number of Crew: ";
	cin>>NumC;

	int id;

	for(int i=0;i<NumP;i++) {

		cout<<"Enter ID for Pilot "<<i+1<<": ";
		cin>>id;

		PilotID.push_back(id);

	}

	for(int i=0;i<NumC;i++) {

		cout<<"Enter ID for Crew Member "<<i+1<<": ";
		cin>>id;

		PilotID.push_back(id);

	}

	cout<<"Enter Start Time/Date: ";
	cin>>StartTime;

	cout<<"Enter End Time/Date: ";
	cin>>EndTime;

	cout<<"Enter Start Airport Code: ";
	cin>>StartCode;

	cout<<"Enter End Airport Code: ";
	cin>>EndCode;

	cout<<"Enter Number of Seats: ";
	cin>>NumPass;

	cout<<"Enter Status: ";
	cin>>fStatus;

	//populates myflight obj
	MyFlight.SetTailNum(Tail);
	MyFlight.SetNumPilots(NumP);
	MyFlight.SetNumCrew(NumC);
	MyFlight.SetPilotIDs(PilotID);
	MyFlight.SetCrewIDs(CrewID);
	MyFlight.SetStartTimeDate(StartTime);
	MyFlight.SetEndTimeDate(EndTime);
	MyFlight.SetStartCode(StartCode);
	MyFlight.SetEndCode(EndCode);
	MyFlight.SetNumPass(NumPass);
	MyFlight.SetStatus(fStatus);

	//appends myflight to flightlist vector
	FlightList.push_back(MyFlight);
	cout<<"Flight Added"<<endl;
}

void Flights::EditFlight() {

	int idChoice;
	int NewInt;
	string NewString;
	string id;
	int c;
	cout<<"Enter Flight ID to Edit: ";
	cin>>id;

	int Index;

	for(int i=0;i<FlightList.size();i++){
		if(FlightList[i].GetTailNum() == id) {
			Index = i;
		}
	}

	//prints edit menu
	cout<<"------------------------------------"<<endl;
	cout<<"|  What would you like to edit?    |"<<endl;
	cout<<"------------------------------------"<<endl;
	cout<<"|                                  |"<<endl;
	cout<<"|  0 - Tail Number                 |"<<endl;
	cout<<"|  1 - Number of Pilots            |"<<endl;
	cout<<"|  2 - Number of Crew              |"<<endl;
	cout<<"|  3 - Pilot Ids                   |"<<endl;
	cout<<"|  4 - Crew Ids                    |"<<endl;
	cout<<"|  5 - Start Time/Date             |"<<endl;
	cout<<"|  6 - End Time/Date               |"<<endl;
	cout<<"|  7 - Start Airport Code          |"<<endl;
	cout<<"|  8 - End Airport Code            |"<<endl;
	cout<<"|  9 - Number of Seats             |"<<endl;
	cout<<"| 10 - Status                      |"<<endl;
	cout<<"|                                  |"<<endl;
	cout<<"------------------------------------"<<endl;

	cin>>c;

	vector<int> pID;
	vector<int> cID;

	switch(c) {
		case 1:

			cout<<"How many Pilots? ";
			cin>>NewInt;
			FlightList[Index].SetNumPilots(NewInt);
			break;

		case 2:

			cout<<"How many Crew? ";
			cin>>NewInt;
			FlightList[Index].SetNumCrew(NewInt);
			break;

		case 3:

			pID=FlightList[Index].GetPilotIDs();
			

			for(int i=0;i<FlightList[Index].GetNumPilots();i++) {
				cout<<"ID 1: "<<pID[i]<<endl;
			}
			cin>>idChoice;

			cout<<"Enter New ID: ";
			cin>>NewInt;
			pID[idChoice-1] = NewInt;
			FlightList[Index].SetPilotIDs(pID);
			break;

		case 4:

			cID=FlightList[Index].GetCrewIDs();
			

			for(int i=0;i<FlightList[Index].GetNumCrew();i++) {
				cout<<"ID 1: "<<cID[i]<<endl;
			}
			cin>>idChoice;

			cout<<"Enter New ID: ";
			cin>>NewInt;
			pID[idChoice-1] = NewInt;
			FlightList[Index].SetCrewIDs(cID);
			break;

		case 5:

			cout<<"Enter New Start Time/Date: ";
			cin>>NewString;
			FlightList[Index].SetStartTimeDate(NewString);
			break;

		case 6:

			cout<<"Enter New End Start/Time: ";
			cin>>NewString;
			FlightList[Index].SetEndTimeDate(NewString);
			break;

		case 7:

			cout<<"Enter New Start Airport Code: ";
			cin>>NewString;
			FlightList[Index].SetStartCode(NewString);
			break;

		case 8:

			cout<<"Enter New End Airport Code: ";
			cin>>NewString;
			FlightList[Index].SetEndCode(NewString);
			break;

		case 9:

			cout<<"Enter New number of Seats: ";
			cin>>NewInt;
			FlightList[Index].SetNumPass(NewInt);
			break;

		case 10:

			cout<<"Enter New Status: ";
			cin>>NewString;
			FlightList[Index].SetStatus(NewString);
			break;

		default:
			cout<<"Invalid Option"<<endl;
			break;


	}

}
void Flights::DeleteFlight() {

	string id;
	cout<<"Enter Flight ID to delete: ";
	cin>>id;

	for(vector<Flight>::iterator it=FlightList.begin();it!=FlightList.end();++it) {
		if((*it).GetTailNum() == id) {
			FlightList.erase(it);
			cout<<"Flight Deleted"<<endl;
			return;
		}
	}
	cout<<"Flight Not Found"<<endl;

}
int Flights::FindFlight() {

	string id;

	cout<<"Enter Flight Tail Number: ";
	cin>>id;

	for(int i=0;i<FlightList.size();i++) {
		if(FlightList[i].GetTailNum() == id) {
			cout<<"Flight Found"<<endl;
			return i;
		}


	}

	cout<<"Flight Not Found"<<endl;
	return -1;

}
void Flights::PrintAllFlights() {

	for(int f=0;f<FlightList.size();f++) {

		cout<<"Tail Number: "<<FlightList[f].GetTailNum()<<endl;
		cout<<"Number of Pilots: "<<FlightList[f].GetNumPilots()<<endl;
		cout<<"Number of Crew: "<<FlightList[f].GetNumCrew()<<endl;
		cout<<"Pilot IDs:"<<endl;
		vector<int> pIDs = FlightList[f].GetPilotIDs();

		for(int i=0;i<FlightList[f].GetNumPilots();i++) {
			cout<<pIDs[i]<< endl;
		}
		cout<<"Crew IDs: "<<endl;
		vector<int> cIDs = FlightList[f].GetCrewIDs();

		for(int i=0;i<FlightList[f].GetNumCrew();i++) {
			cout<<cIDs[i]<< endl;
		}
		cout<<"Start Time/Date: "<<FlightList[f].GetStartTimeDate()<<endl;
		cout<<"End Time/Date: "<<FlightList[f].GetEndTimeDate()<<endl;
		cout<<"Start Airport Code: "<<FlightList[f].GetStartAirportCode()<<endl;
		cout<<"End Airport Code: "<<FlightList[f].GetEndAirportCode()<<endl;
		cout<<"Number of Seats: "<<FlightList[f].GetNumPassengers()<<endl;
		cout<<"Status: "<<FlightList[f].GetStatus()<<endl;
	}

}
void Flights::PrintFlight() {

	int f, index = 0;
	string id;

	cout<<"Enter Flight ID to Print: ";
	cin>>id;

	int i = 0;
	for(vector<Flight>::iterator it=FlightList.begin();it!=FlightList.end();it++) {
		if((*it).GetTailNum() == id) {
			index=i;
			break;
		}
		i++;
	}

	if(f==-1) {
		return;
	}

	cout<<"Tail Number: "<<FlightList[f].GetTailNum()<<endl;
	cout<<"Number of Pilots: "<<FlightList[f].GetNumPilots()<<endl;
	cout<<"Number of Crew: "<<FlightList[f].GetNumCrew()<<endl;
	
	cout<<"Pilot IDs:"<<endl;
	vector<int> pIDs = FlightList[f].GetPilotIDs();
	for(int i=0;i<FlightList[f].GetNumPilots();i++) {
		cout<<pIDs[i]<< endl;
	}

	cout<<"Crew IDs: "<<endl;
	vector<int> cIDs = FlightList[f].GetCrewIDs();
	for(int i=0;i<FlightList[f].GetNumCrew();i++) {
		cout<<cIDs[i]<< endl;
	}
	cout<<"Start Time/Date: "<<FlightList[f].GetStartTimeDate()<<endl;
	cout<<"End Time/Date: "<<FlightList[f].GetEndTimeDate()<<endl;
	cout<<"Start Airport Code: "<<FlightList[f].GetStartAirportCode()<<endl;
	cout<<"End Airport Code: "<<FlightList[f].GetEndAirportCode()<<endl;
	cout<<"Number of Seats: "<<FlightList[f].GetNumPassengers()<<endl;
	cout<<"Status: "<<FlightList[f].GetStatus()<<endl;

}

void Flights::PrintFlight(int f) {

	cout<<"Tail Number: "<<FlightList[f].GetTailNum()<<endl;
	cout<<"Number of Pilots: "<<FlightList[f].GetNumPilots()<<endl;
	cout<<"Number of Crew: "<<FlightList[f].GetNumCrew()<<endl;
	
	cout<<"Pilot IDs:"<<endl;
	vector<int> pIDs = FlightList[f].GetPilotIDs();
	for(int i=0;i<FlightList[f].GetNumPilots();i++) {
		cout<<pIDs[i]<< endl;
	}

	cout<<"Crew IDs: "<<endl;
	vector<int> cIDs = FlightList[f].GetCrewIDs();
	for(int i=0;i<FlightList[f].GetNumCrew();i++) {
		cout<<cIDs[i]<< endl;
	}
	cout<<"Start Time/Date: "<<FlightList[f].GetStartTimeDate()<<endl;
	cout<<"End Time/Date: "<<FlightList[f].GetEndTimeDate()<<endl;
	cout<<"Start Airport Code: "<<FlightList[f].GetStartAirportCode()<<endl;
	cout<<"End Airport Code: "<<FlightList[f].GetEndAirportCode()<<endl;
	cout<<"Number of Seats: "<<FlightList[f].GetNumPassengers()<<endl;
	cout<<"Status: "<<FlightList[f].GetStatus()<<endl;

}

void Flights::SaveFlight() {

	ofstream fout;
	fout.open("flights.data");
	fout<<FlightList.size()<<endl;

	for(int f=0;f<FlightList.size();f++) {
		fout<< FlightList[f].GetTailNum() <<endl;
		fout<< FlightList[f].GetNumPilots() <<endl;
		fout<< FlightList[f].GetNumCrew() <<endl;

		vector<int> pIDs = FlightList[f].GetPilotIDs();
		for(int i=0;i<FlightList[f].GetNumPilots();i++) {
			fout<<pIDs[i]<< endl;
		}

		vector<int> cIDs = FlightList[f].GetCrewIDs();
		for(int i=0;i<FlightList[f].GetNumCrew();i++) {
			fout<<cIDs[i]<< endl;
		}
		
		fout<< FlightList[f].GetStartTimeDate() <<endl;
		fout<< FlightList[f].GetEndTimeDate() <<endl;
		fout<< FlightList[f].GetStartAirportCode() <<endl;
		fout<< FlightList[f].GetEndAirportCode() <<endl;
		fout<< FlightList[f].GetNumPassengers() <<endl;
		fout<< FlightList[f].GetStatus() <<endl;
		


	}
	fout.close();
}
void Flights::LoadFlight() {

	ifstream fin;
	int size;
	fin.open("flights.data");
	fin>>size;

	for(int i=0;i<FlightList.size();i++) {
		
		Flight tFlight;
		string s;
		int n;

		fin>>s;
		tFlight.SetTailNum(s);
		fin>>n;
		tFlight.SetNumPilots(n);
		fin>>n;
		tFlight.SetNumCrew(n);
		



		vector<int> pIDs;
		for(int i=0;i<tFlight.GetNumPilots();i++) {
			fin>>n;
			pIDs.push_back(n);
		}
		tFlight.SetPilotIDs(pIDs);

		vector<int> cIDs;
		for(int i=0;i<tFlight.GetNumCrew();i++) {
			fin>>n;
			cIDs.push_back(n);
		}
		tFlight.SetCrewIDs(cIDs);

		fin>>s;
		tFlight.SetStartTimeDate(s);
		fin>>s; 
		tFlight.SetEndTimeDate(s);
		fin>>s;
		fin>>s; 
		tFlight.SetStartCode(s);
		fin>>s;
		tFlight.SetEndCode(s);
		fin>>n;
		tFlight.SetNumPass(n);
		fin>>s;
		tFlight.SetStatus(s);
		

		FlightList.push_back(tFlight);
	}
	fin.close();
	cout<<"Flights Loaded"<<endl;
}

void Flights::PrintByStatus(string s) {

	for(int i=0;i<FlightList.size();i++) {
		if(FlightList[i].GetStatus() == s) {
			PrintFlight(i);
		}
	}

}

void Flights::DeleteByStatus(string s) {

	for(vector<Flight>::iterator it=FlightList.begin();it!=FlightList.end();it++) {
		if((*it).GetStatus() == s) {
			FlightList.erase(it);
		}
	}

}


void Flights::PrintCrewAssignments() {

	int id;

	cout<<"Enter Crew ID: ";
	cin>>id;

	bool t = false;
	for(int i=0;i<FlightList.size();i++) {
		if(FlightList[i].ContainsID(id)) {

			cout<<"Start Time/Date: "<<FlightList[i].GetStartTimeDate()<<endl;
			cout<<"End Time/Date: "<<FlightList[i].GetEndTimeDate()<<endl;
			cout<<"Start Airport Code: "<<FlightList[i].GetStartAirportCode()<<endl;
			cout<<"End Airport Code: "<<FlightList[i].GetEndAirportCode()<<endl;
			cout<<endl;

			t=true;
		}
	}
	if(t==false) {
		cout<<"No Assignments Found"<<endl;
	}
}