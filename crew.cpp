#include<iostream>
#include<string>
#include<vector>
#include"crew.h"


void Crew::SetName(string n) {
    Name = n;
}

void Crew::SetID(int id) {
  IDNum = id;
}

void Crew::SetType(string t) {
  Type = t;
}

string Crew::GetName() {
  return Name;
}

int Crew::GetID() {
  return IDNum;
}

string Crew::GetType() {
  return Type;
}
