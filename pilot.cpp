#include"pilot.h"
#include"crew.h"

void Pilot::SetRating(string r) {
	Rating = r;
}
void Pilot::SetHours(int h) {
	flightHours = h;
}
string Pilot::GetRating(){
	return Rating;
}
int Pilot::GetHours(){
	return flightHours;
}
void Pilot::PrintInfo(){
	Crew::PrintInfo();
	cout<<"Rating: "<<Rating<<endl;
	cout<<"Cumulative Flight Hours: "<<flightHours<<endl;
}
void Pilot::SaveInfo(ofstream &fout){
		fout<<"pilot"<<endl;
		Crew::SaveInfo(fout);
		fout<<Rating<<endl;
		fout<<flightHours<<endl;

		

}
string Pilot::GetCrewType() {
  return "Pilot";
}