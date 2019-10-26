#ifndef CREW_H
#define CREW_H

#include<iostream>
#include<string>
#include<vector>
using namespace std;



class Crew {
  private:
    string Name;
    string IDNum;
    string Type;
  public:
    void SetName(string n);
    void SetID(string id);
    void SetType(string t);

    string GetName();
    string GetID();
    string GetType();


};

#endif
