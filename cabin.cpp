#include<iostream>
#include<fstream>
#include"cabin.h"
#include"crew.h"

void Cabin::SetPosition(CabinPosition p) {
	Position = p;
}
void Cabin::SetPosition(int p) {
	Position = static_cast<CabinPosition>(p);
}
CabinPosition Cabin::GetPosition(){
	return Position;
}
string Cabin::GetCrewType() {
	return "Cabin";
}
void Cabin::PrintInfo() {
	Crew::PrintInfo();

	cout<<"Position: "<<StrPosition(Position)<<endl;
}
void Cabin::SaveInfo(ofstream &fout){
	fout<<"cabin"<<endl;
	Crew::SaveInfo(fout);	
	fout<<Position<<endl;	

}
string Cabin::StrPosition(CabinPosition n) {
	switch(n) { 
		case 0:
			return "First Class";
		case 1:
			return "Business Class";
		case 2:
			return "Economy Front";
		case 3:
			return "Economy Rear";
		case 4:
			return "Lead";
	}
}