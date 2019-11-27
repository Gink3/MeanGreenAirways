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
void Pilot::Save(){
	
		ofstream fout;
		fout.open("crew.data");
		
		fout<<Rating<<endl;
		fout<<flightHours<<endl;

		fout.close();

}