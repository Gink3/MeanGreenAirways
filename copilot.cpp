#include<iostream>
#include"copilot.h"


void Copilot::SetRating(string r) {
	Rating = r;
}
void Copilot::SetHours(int h) {
	flightHours = h;
}
string Copilot::GetRating() {
	return Rating;
}
int Copilot::GetHours(){
	return flightHours;
}

void Copilot::PrintInfo() {
	Crew::PrintInfo();
	cout<<"Rating: "<<Rating<<endl;
	cout<<"Cumulative Flight Hours: "<<flightHours<<endl;
}
