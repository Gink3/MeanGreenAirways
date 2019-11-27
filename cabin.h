#ifndef CABIN_H
#define CABIN_H

#include<string>
#include"crew.h"


class Cabin : public Crew {
	private:
		string Position;


	public:
		void SetPosition(string p);

		string GetPosition();

		void PrintInfo();
		void Save();
};


#endif
