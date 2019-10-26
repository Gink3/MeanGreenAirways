#ifndef CREW_H
#define CREW_H

#include<iostream>
#include<string>
#include<vector>
using namespace std;



class Crew {
  private:
    string Name;
    int IDNum;
    string Type;
  public:
    void SetName(string n);
    void SetID(int id);
    void SetType(string t);

    string GetName();
    int GetID();
    string GetType();


};

#endif
