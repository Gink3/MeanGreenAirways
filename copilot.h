#ifndef COPILOT_H
#define COPILOT_H

#include<fstream>
#include"crew.h"
using namespace std;
class Copilot : public Crew {
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
};

#endif
