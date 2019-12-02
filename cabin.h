#ifndef CABIN_H
#define CABIN_H

#include<string>
#include"crew.h"
using namespace std;

enum CabinPosition {FirstClass=0, BusinessClass, EconomyFront, EconomyRear, Lead};

class Cabin : public Crew {
	private:
		CabinPosition Position;
		

	public:
		void SetPosition(CabinPosition p);
		void SetPosition(int p);
		CabinPosition GetPosition();

		string GetCrewType();
		void PrintInfo();
		void SaveInfo(ofstream &fout);
		string StrPosition(CabinPosition n);
};


#endif
