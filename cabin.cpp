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
	cout<<"Position: "<<Position<<endl;
}
void Cabin::SaveInfo(ofstream &fout){
	fout<<"cabin"<<endl;
	Crew::SaveInfo(fout);	
	fout<<Position<<endl;
		

		

}