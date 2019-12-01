#ifndef FLIGHT_H
#define FLIGHT_H

#include<iostream>
#include<string>
#include<vector>
#include"crew.h"
using namespace std;


class Flight {
  private:
    string TailNum;
    int NumPilots; //flights with > 8 hours require 2 pilots and 2 co pilots
    int NumCrew;
    vector<int> PilotIDs;
    vector<int> CopilotIDs;
    vector<int> CrewIDs;
    string StartTimeDate;
    string EndTimeDate;
    string StartAirportCode;
    string EndAirportCode;
    int NumPassengers;
    string Status;

  public:
    void SetTailNum(string t);
    void SetNumPilots(int p);
    void SetNumCrew(int c);

    void SetPilotIDs(vector<int> id);
    void SetCrewIDs(vector<int> id);

    void AddPilotID(int n);
    void RemovePilotID(int id);

    void AddCopilotID(int n);
    void RemoveCopilotId(int n);

    void AddCrewID(int n);
    void RemoveCrew(int id);

    void SetStartTimeDate(string start);
    void SetEndTimeDate(string end);

    void SetStartCode(string start);
    void SetEndCode(string end);

    void SetNumPass(int p);
    void SetStatus(string status);

    string GetTailNum();
    int GetNumPilots();
    int GetNumCrew();
    vector<int> GetPilotIDs();
    vector<int> GetCrewIDs();
    string GetStartTimeDate();
    string GetEndTimeDate();
    string GetStartAirportCode();
    string GetEndAirportCode();
    int GetNumPassengers();
    string GetStatus();

    bool ContainsID(int id); //returns true if crew member id in either pilot/crew vectors

};

#endif
