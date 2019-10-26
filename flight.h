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
    vector<string> PilotIDs;
    vector<string> CrewIDs;
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

    void SetPilotIDs(vector<string> id);
    void SetCrewIDs(vector<string> id);

    void AddPilot();
    void RemovePilot(string id);

    void AddCrew();
    void RemoveCrew(string id);

    void SetStartTimeDate(string start);
    void SetEndTimeDate(string end);

    void SetStartCode(string start);
    void SetEndCode(string end);

    void SetNumPass(int p);
    void SetStatus(string status);

    string GetTailNum();
    int GetNumPilots();
    int GetNumCrew();
    vector<string> GetPilotIDs();
    vector<string> GetCrewIDs();
    string GetStartTimeDate();
    string GetEndTimeDate();
    string GetStartAirportCode();
    string GetEndAirportCode();
    int GetNumPassengers();
    string GetStatus();

    bool ContainsID(string id); //returns true if crew member id in either pilot/crew vectors

};

#endif
