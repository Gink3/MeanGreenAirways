#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"planes.h"
using namespace std;

void Planes::AddPlane() {
	Plane p;
	string s;
	int n;

	cout<<"Enter Make: ";
	cin>> s;
	p.SetMake(s);

	cout<<"Enter Model: ";
	cin>>s;
	p.SetModel(s);

	cout<<"Enter Tail Number: ";
	cin>>s;
	p.SetTailNum(s);

	cout<<"Enter Number of Seats: ";
	cin>>n;
	p.SetNumSeats(n);

	cout<<"Enter Range: ";
	cin>>n;
	p.SetRange(n);

	PlaneList.push_back(p);

}

void Planes::AddPlane(Plane p) {
	for(vector<Plane>::iterator it=PlaneList.begin();it!=PlaneList.end();++it) {
		if(p.GetTailNum() == (*it).GetTailNum()) {
			cout<<"Plane already exists"<<endl;
		}

	}
	PlaneList.push_back(p);
	cout<<"Plane Added"<<endl;
}

void Planes::EditPlane() {

	string tail, s;
	int c, index, n;

	cout<<"Please Enter a Tail Number: "<<endl;
	cin>>tail;

	cout<<"--------------------------------------"<<endl;
	cout<<"| Please Select the element to Edit  |"<<endl;
	cout<<"--------------------------------------"<<endl;
	cout<<"|                                    |"<<endl;
	cout<<"| 0 - Make                           |"<<endl;
	cout<<"| 1 - Model                          |"<<endl;
	cout<<"| 2 - Tail Number                    |"<<endl;
	cout<<"| 3 - Number of Seats                |"<<endl;
	cout<<"| 4 - Range                          |"<<endl;
	cout<<"| 5 - Minimum Crew                   |"<<endl;
	cout<<"|                                    |"<<endl;
	cout<<"--------------------------------------"<<endl;




	int i=0;
	for(vector<Plane>::iterator it=PlaneList.begin();it!=PlaneList.end();++it) {
		if((*it).GetTailNum() == tail) {
			
			index =i;
		}
		i++;
	}


	if(c==0) {

		cout<<"Please Enter a new Make: "<<endl;
		cin>>s;
		PlaneList[index].SetMake(s);
		cout<<"New Make Set"<<endl;

	}else if(c==1) {

		cout<<"Please Enter a new Model: "<<endl;
		cin>>s;
		PlaneList[index].SetModel(s);
		cout<<"New Model Set"<<endl;

	}else if(c==2) {

		cout<<"Please Enter a new Tail Number: "<<endl;
		cin>>s;
		PlaneList[index].SetTailNum(s);
		cout<<"New Tail Number Set"<<endl;

	}else if(c==3) {

		cout<<"Please Enter a new Number of Seats:"<<endl;
		cin>>n;
		PlaneList[index].SetNumSeats(n);
		cout<<"New Number of Seats Set"<<endl;

	}else if(c==4) {

		cout<<"Please Enter a new Range: "<<endl;
		cin>>n;
		PlaneList[index].SetRange(n);

	}else if(c==5) {

		cout<<"Please Enter a new Minimum Crew: "<<endl;
		cin>>n;
		PlaneList[index].SetMinCrew(n);
	}


}
void Planes::DeletePlane() {

	string tail;

	cout<<"Enter Plane Tail Number";
	cin>>tail;

	for(vector<Plane>::iterator it=PlaneList.begin();it!=PlaneList.end();++it) {
		if((*it).GetTailNum() == tail) {
			PlaneList.erase(it);
			cout<<"Plane Deleted"<<endl;
			return;
		}
		
	}
	cout<<"Plane not found"<<endl;

}
int Planes::FindPlane() {
	
	string tailNum;
	cout<<"Enter Plane Tail Number: ";
	cin>>tailNum;


	int index =0;

	for(vector<Plane>::iterator it=PlaneList.begin();it!=PlaneList.end();++it) {
		if((*it).GetTailNum() == tailNum) {
			cout<<"Plane Found"<< endl;
			return index;
		}
		index++;
	}
	cout<<"Plane Not Found"<<endl;
	return -1;
}
int Planes::FindPlane(string s) {
	int index =0;

	for(vector<Plane>::iterator it=PlaneList.begin();it!=PlaneList.end();++it) {
		if((*it).GetTailNum() == s) {
			cout<<"Plane Found"<< endl;
			return index;
		}
		index++;
	}
	cout<<"Plane not Found"<<endl;
	return -1;
}
void Planes::PrintAllPlanes() {
	
	for(vector<Plane>::iterator it=PlaneList.begin();it!=PlaneList.end();++it) {
		
		cout<<"Make: "<<(*it).GetMake()<<endl;
		cout<<"Model: "<<(*it).GetModel()<<endl;
		cout<<"Tail Number: "<<(*it).GetTailNum()<<endl;
		cout<<"Number of Seats: "<<(*it).GetRange()<<endl;
		cout<<"Minimum Crew: "<<(*it).GetMinCrew()<<endl;

		cout << endl;
	}

}
void Planes::PrintPlane() {

	int index;

	cout<<"Enter Plane ID to Print: ";
	cin>>index;

	cout<<"Make: "<< PlaneList[index].GetMake()<<endl;
	cout<<"Model: "<< PlaneList[index].GetModel()<<endl;
	cout<<"Tail Number: "<< PlaneList[index].GetTailNum()<<endl;
	cout<<"Number of Seats: " <<PlaneList[index].GetRange()<<endl;
	cout<<"Minimum Crew: "<<PlaneList[index].GetMinCrew()<<endl;

}



void Planes::SavePlane() {
	
	//opens file for saving data
	ofstream fout;
	fout.open("planes.data");
	fout<<PlaneList.size()<<endl;
	
	for(int i=0; i<PlaneList.size(); i++) {
		fout << PlaneList[i].GetMake()<<endl;
		fout << PlaneList[i].GetModel()<<endl;
		fout << PlaneList[i].GetTailNum()<<endl;
		fout << PlaneList[i].GetNumSeats()<<endl;
		fout << PlaneList[i].GetRange()<<endl;
		fout << PlaneList[i].GetMinCrew()<<endl;
		
	}
	
	fout.close();
}


void Planes::LoadPlane() {
	cout<<"Loading Planes"<<endl;
	int size=0;
	Plane MyPlane;
	string PlaneMake;
	string PlaneModel;
	string PlaneTail;
	int PlaneNumSeats;
	int PlaneRange;
	int MinC;

	//opens file for loading data
	ifstream fin;
	fin.open("planes.data");
	fin >> size;
	
	for(int i=0; i <size; i++) {

		fin>>PlaneMake;
		fin>>PlaneModel;
		fin>>PlaneTail;
		fin>>PlaneNumSeats;
		fin>>PlaneRange;
		fin>>MinC;

		MyPlane.SetMake(PlaneMake);
		MyPlane.SetModel(PlaneModel);
		MyPlane.SetTailNum(PlaneTail);
		MyPlane.SetNumSeats(PlaneNumSeats);
		MyPlane.SetRange(PlaneRange);
		MyPlane.SetMinCrew(MinC);
		
		PlaneList.push_back(MyPlane);
	}
	
	fin.close();
	cout<<"Planes Loaded"<<endl;

}	


void Planes::PrintPlaneAssignments() {

	string s;

	cout<<"Enter Tail Number: ";
	cin>>s;

	for(int i=0;i<PlaneList.size();i++) {
		if(PlaneList[i].GetTailNum() == s) {
			
		cout<<"Make: "<< PlaneList[i].GetMake()<<endl;
		cout<<"Model: "<< PlaneList[i].GetModel()<<endl;
		cout<<"Tail Number: "<< PlaneList[i].GetTailNum()<<endl;
		cout<<"Number of Seats: " <<PlaneList[i].GetRange()<<endl;
		cout<<"Minimum Crew: "<<PlaneList[i].GetMinCrew()<<endl;

		}
	}

}

