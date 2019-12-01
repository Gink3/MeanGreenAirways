#include<iostream>
#include<fstream>
#include"cabin.h"
#include"crew.h"

void Cabin::SetPosition(CabinPosition p) {
	Position = p;
}
CabinPosition Cabin::GetPosition(){
	return Position;
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