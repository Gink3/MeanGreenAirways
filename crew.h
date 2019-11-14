#ifndef CREW_H
#define CREW_H

#include<iostream>
#include<string>
#include<vector>
using namespace std;



class Crew {
  protected:
    string Name;
    string IDNum;
    string Status;
  public:
    void SetName(string n);
    void SetID(string id);
    void SetStatus(string s);

    string GetName();
    string GetID();
    string GetStatus();


};

#endif
