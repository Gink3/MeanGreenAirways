#include<iostream>
#include<fstream>
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
void Copilot::SaveInfo(ofstream &fout){
		fout<<"copilot"<<endl;
		Crew::SaveInfo(fout);
		fout<<Rating<<endl;
		fout<<flightHours<<endl;
}
string Copilot::GetCrewType() {
  return "Copilot";
}