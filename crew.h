#ifndef CREW_H
#define CREW_H

#include<iostream>
#include<fstream>
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
    void SetStatus(int n);

    string GetName();
    int GetID();
    string GetStatus();
    int GetStatusInt();

    virtual void PrintInfo();
    virtual void SaveInfo(ofstream &fout);
    virtual string GetCrewType();
};

#endif
