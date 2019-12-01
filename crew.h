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
    virtual void SetRating(string r) = 0;
    virtual void SetHours(int h) = 0;
    virtual void SetPosition(int p) =0;
    virtual string GetCrewType();
};

#endif
