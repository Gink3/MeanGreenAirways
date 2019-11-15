#include<iostream>
#include"crew.h"

void Cabin::SetPosition(string p) {
	Position = p;
}
string Cabin::GetPosition(){
	return Position;
}
void PrintInfo() {
	Crew::PrintInfo();
	cout<<"Position: "<<Position<<endl;
}
