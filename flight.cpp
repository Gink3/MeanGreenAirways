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
void Flight::SetPilotIDs(vector<string> id) {
    PilotIDs = id;
}

void Flight::SetCrewIDs(vector<string> id) {
    CrewIDs = id;
}

//adds Crew Id given crew obj info
void Flight::AddPilot() {

    Crew p;
    string s;

    cout<<"Enter Pilot name: ";
    cin>>s;
    p.SetName(s);

    cout<<"Enter Pilot Id: ";
    cin>>s;
    p.SetID(s);

    p.SetStatus("Pilot");




    if(p.GetStatus() != "Pilot") {
        cout<<"Error: Incorrect Crew Status" << endl;
        return;
    }

     for(vector<string>::iterator it=PilotIDs.begin();it!=PilotIDs.end();++it) {
        if((*it) == p.GetID()) {
            cout<<"Pilot Already Added"<<endl;
            return;
        }
     }
    PilotIDs.push_back(p.GetID());
}
void Flight::RemovePilot(string id) {
    for(vector<string>::iterator it=PilotIDs.begin();it!=PilotIDs.end();++it) {
        if((*it) == id) {
            PilotIDs.erase(it);
            cout << "Successfully removed" << endl;
            return;
        }
    }
    cout<<"No Pilot found with ID: " << id << endl;


}

void Flight::AddCrew() {
    
    Crew c;
    string s;
    

    cout<<"Enter Crew Member name: ";
    cin>>s;
    c.SetName(s);

    cout<<"Enter Crew Member ID:";
    cin>>s;
    c.SetID(s);


    if(c.GetStatus() != "Cabin") {
        cout<<"Error: Incorrect Crew Type" << endl;
        return;
    }

    CrewIDs.push_back(c.GetID());

}

void Flight::RemoveCrew(string id) {

     for(vector<string>::iterator it=CrewIDs.begin();it!=CrewIDs.end();++it) {
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
vector<string> Flight::GetPilotIDs() {
    return PilotIDs;
}
vector<string> Flight::GetCrewIDs() {
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

bool Flight::ContainsID(string id) {

    for(vector<string>::iterator it=PilotIDs.begin();it!=PilotIDs.end();it++) {
        if((*it) == id) {
            return true;
        }
    }
    for(vector<string>::iterator it=CrewIDs.begin();it!=CrewIDs.end();it++) {
        if((*it) == id) {
            return true;
        }
    }
    return false;

}