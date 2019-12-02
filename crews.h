#ifndef CREWS_H
#define CREWS_H

#include<iostream>
#include<string>
#include<vector>
#include"crew.h"
#include"cabin.h"
#include"pilot.h"
#include"copilot.h"

using namespace std;

class Crews {
  private:
    int count;
    vector<Crew*> CrewList;

  public:

    void AddCrew();
    void AddCrew(Crew *c);
    void EditCrew();
    void DeleteCrew();       
    void DeleteCrew(int id); //overload for preselected deletion
    int FindCrew(int id);    //finds crew with certain id; returns index of crew
    void PrintAllCrew();     //prints all crew members
    void PrintCrew();        //prints a user selected member
    bool IDtaken(int id);

    void virtual SaveCrew();         //saves all crew data
    void virtual LoadCrew();         //loads all crew data


};

#endif