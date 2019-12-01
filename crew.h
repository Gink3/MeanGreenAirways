#ifndef CREW_H
#define CREW_H

#include<iostream>
#include<string>
#include<vector>
using namespace std;



class Crew {
  protected:
    string Name;
    int IDNum;
    string Status;
  public:
    void SetName(string n);
    void SetID(int id);
    void SetStatus(string s);

    string GetName();
    int GetID();
    string GetStatus();

    virtual void PrintInfo();
    virtual void SaveInfo(ofstream &fout);
};

#endif
