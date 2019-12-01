#include<iostream>
#include<string>
#include<vector>
#include"flight.h"    


using namespace std;

void Flight::SetTailNum(string t) {
    TailNum = t;
}
void Flight::SetNumPilots(int p) {
    NumPilots = p;
}

void Flight::SetNumCrew(int c) {
    NumCrew = c;
}
void Flight::SetPilotIDs(vector<int> id) {
    PilotIDs = id;
}

void Flight::SetCrewIDs(vector<int> id) {
    CrewIDs = id;
}

void Flight::AddPilotID(int n ) {
    PilotIDs.push_back(n);
}

void Flight::RemovePilotID(int id) {
    for(vector<int>::iterator it=PilotIDs.begin();it!=PilotIDs.end();++it) {
        if((*it) == id) {
            PilotIDs.erase(it);
            cout << "Successfully removed" << endl;
            return;
        }
    }
    cout<<"No Pilot found with ID: " << id << endl;


}
void Flight::AddCopilotID(int n) {
    CopilotIDs.push_back(n);
}
void Flight::RemoveCopilotId(int n) {
    for(vector<int>::iterator it=CopilotIDs.begin();it!=CopilotIDs.end();it++) {
        if(*it == n) {
            CopilotIDs.erase(it);
            cout<<"Successfully removed"<<endl;
            break;
        }
    }
    cout<<"Not found"<<endl;
}
void Flight::AddCrewID(int n) {
    CrewIDs.push_back(n);
}

void Flight::RemoveCrew(int id) {

     for(vector<int>::iterator it=CrewIDs.begin();it!=CrewIDs.end();++it) {
        if((*it) == id) {
            PilotIDs.erase(it);
            cout << "Successfully removed" << endl;
            return;
        }
    }
    cout<<"No Crew found with ID: " << id << endl; 

}


void Flight::SetStartTimeDate(string start) {
    StartTimeDate = start;
}
void Flight::SetEndTimeDate(string end) {
    EndTimeDate = end;
}


void Flight::SetStartCode(string start) {
    StartAirportCode = start;
}
void Flight::SetEndCode(string end) {
    EndAirportCode = end;
}

void Flight::SetNumPass(int p) {
    NumPassengers = p;
}
void Flight::SetStatus(string status) {
    Status = status;
}

string Flight::GetTailNum() {
    return TailNum;
}
int Flight::GetNumPilots() {
    return NumPilots;
}
int Flight::GetNumCrew() {
    return NumCrew;
}
vector<int> Flight::GetPilotIDs() {
    return PilotIDs;
}
vector<int> Flight::GetCrewIDs() {
    return CrewIDs;
}
string Flight::GetStartTimeDate() {
    return StartTimeDate;
}
string Flight::GetEndTimeDate() {
    return EndTimeDate;
}


string Flight::GetStartAirportCode() {
    return StartAirportCode;
}
string Flight::GetEndAirportCode() {
    return EndAirportCode;
}
int Flight::GetNumPassengers() {
    return NumPassengers;
}
string Flight::GetStatus() {
    return Status;
}

bool Flight::ContainsID(int id) {

    for(vector<int>::iterator it=PilotIDs.begin();it!=PilotIDs.end();it++) {
        if((*it) == id) {
            return true;
        }
    }
    for(vector<int>::iterator it=CrewIDs.begin();it!=CrewIDs.end();it++) {
        if((*it) == id) {
            return true;
        }
    }
    return false;

}