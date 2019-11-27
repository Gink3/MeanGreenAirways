#include<iostream>
#include<fstream>
#include"cabin.h"
#include"crew.h"

void Cabin::SetPosition(string p) {
	Position = p;
}
string Cabin::GetPosition(){
	return Position;
}
void Cabin::PrintInfo() {
	Crew::PrintInfo();
	cout<<"Position: "<<Position<<endl;
}
void Cabin::Save(){
	
		ofstream fout;
		fout.open("crew.data");
		
		fout<<Position<<endl;
		

		fout.close();

}