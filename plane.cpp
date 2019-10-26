#include<iostream>
#include<string>
#include<vector>
#include"plane.h"
using namespace std;

void Plane::SetMake(string m) {
  Make = m;
}

void Plane::SetModel(string m) {
  Model = m;
}

void Plane::SetTailNum(string t) {
  TailNum = t;
}

void Plane::SetNumSeats(int s) {
  NumSeats = s;
}

void Plane::SetRange(int r) {
  Range = r;
}

void Plane::SetMinCrew(int c) {
  MinCrew = c;
}


string Plane::GetMake() {
  return Make;
}

string Plane::GetModel() {
  return Model;
}

string Plane::GetTailNum() {
  return TailNum;
}

int Plane::GetNumSeats() {
  return NumSeats;
}

int Plane::GetRange() {
  return Range;
}

int Plane::GetMinCrew() {
  return MinCrew;
}


