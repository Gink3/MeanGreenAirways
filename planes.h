#ifndef PLANES_H
#define PLANES_H

#include<iostream>
#include<string>
#include<vector>
#include"plane.h"

class Planes {
  private:
    int count;
    vector<Plane> PlaneList;

  public:

    void AddPlane();
    void AddPlane(Plane p); 
    void EditPlane();
    void DeletePlane();
    int FindPlane();
    int FindPlane(string s);
    void PrintAllPlanes();
    void PrintPlane();

    void SavePlane();
    void LoadPlane();

    void PrintPlaneAssignments(); //prints all plane assignments
};

#endif
