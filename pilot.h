#ifndef PILOT_H
#define PILOT_H

#include<iostream>
#include<string>
#include<fstream>
#include"crew.h"
using namespace std;
class Pilot : public Crew {
	private:
		string Rating;
		int flightHours;
	public:
		void SetRating(string r);
		void SetHours(int h);

		string GetRating();
		int GetHours();

		void PrintInfo();

		void SaveInfo(ofstream &fout);
		string GetCrewType();
};


#endif