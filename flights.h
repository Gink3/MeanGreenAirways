#ifndef FLIGHTS_H
#define FLIGHTS_H

#include<iostream>
#include<string>
#include<vector>
#include"flight.h"
using namespace std;

class Flights {
  private:

    int count;
    vector<Flight> FlightList;

  public:
  	
  	void AddFlight();
  	void EditFlight();
  	void DeleteFlight();
  	int FindFlight();
  	
    void PrintAllFlights();
  	void PrintFlight();
    void PrintFlight(int f);

    void SaveFlight();
    void LoadFlight();

    void PrintByStatus(string s); //prints everything with given status
    void DeleteByStatus(string s); //deletes everything with given status

    void PrintCrewAssignments();

    
};

#endif
