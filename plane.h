#ifndef PLANE_H
#define PLANE_H


#include<iostream>
#include<string>
#include<vector>
using namespace std;


class Plane {
  private:
    string Make;
    string Model;
    string TailNum;
    int NumSeats;
    int Range;
    int MinCrew;

  public:
    void SetMake(string m);
    void SetModel(string m);
    void SetTailNum(string t);
    void SetNumSeats(int s);
    void SetRange(int r);
    void SetMinCrew(int c);

    string GetMake();
    string GetModel();
    string GetTailNum();
    int GetNumSeats();
    int GetRange();
    int GetMinCrew();

   
};

#endif
