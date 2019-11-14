#include<iostream>
#include<string>
#include<vector>
#include"crew.h"


void Crew::SetName(string n) {
    Name = n;
}

void Crew::SetID(string id) {
  IDNum = id;
}

void Crew::SetStatus(string s) {
  Status = s;
}

string Crew::GetName() {
  return Name;
}

string Crew::GetID() {
  return IDNum;
}

string Crew::GetStatus() {
  return Status;
}
