#include<iostream>
#include<string>
#include"crew.h"
#include"plane.h"
#include"flight.h"
#include"crews.h"
#include"planes.h"
#include"flights.h"
using namespace std;

/*
*
*  Taylor King
*  taylorking5@my.unt.edu
*  
*  Places and schedules flights and plane crews
*  for mean green airlines
*
*
*
*
*
*
*
*/




//displays main menu and returns user choice
int mainMenu() {
	int c;

	cout<<"-----------------------------------"<<endl;
	cout<<"| Please Select an Action         |"<<endl;
	cout<<"-----------------------------------"<<endl;
	cout<<"|                                 |"<<endl;
	cout<<"|  0 - Quit                       |"<<endl;
	cout<<"|  1 - Add a Crew Member          |"<<endl;
	cout<<"|  2 - Edit a Crew Member         |"<<endl;
	cout<<"|  3 - Delete a Crew Member       |"<<endl;
	cout<<"|  4 - Add a Flight               |"<<endl;
	cout<<"|  5 - Edit a Flight              |"<<endl;
	cout<<"|  6 - Delete a Flight            |"<<endl;
	cout<<"|  7 - Add a Plane                |"<<endl;
	cout<<"|  8 - Edit a Plane               |"<<endl;
	cout<<"|  9 - Delete a Plane             |"<<endl;
	cout<<"| 10 - Print a Plane              |"<<endl;
	cout<<"| 11 - Print all Planes           |"<<endl;
	cout<<"| 12 - Print all Crew             |"<<endl;
	cout<<"| 13 - Print Flight               |"<<endl;
	cout<<"| 14 - Print all Flights          |"<<endl;
	cout<<"| 15 - Print Crew Assignments     |"<<endl;
	cout<<"| 16 - Print Plane Assignments    |"<<endl;
	cout<<"| 17 - Load all data              |"<<endl;
	cout<<"| 18 - Save all data              |"<<endl;
	cout<<"|                                 |"<<endl;
	cout<<"-----------------------------------"<<endl;

	cin >> c;
	if (c > 18) {
		cout<<"Invalid Answer"<<endl;
		c = mainMenu();
	} 


	return c;

}

int main() {

	Flights fl;
	Planes pl;
	Crews cl;

	fl.LoadFlight();
	pl.LoadPlane();
	cl.LoadCrew();


	int choice;

	

	//main loop of the program
	do {
		
		choice = mainMenu();

		switch(choice) {

				//add crew
				case 1:

					cl.AddCrew();
					cl.SaveCrew();
					break;
				//edit crew
				case 2:

					cl.EditCrew();
					cl.SaveCrew();
					break;
				//delete crew
				case 3:

					cl.DeleteCrew();
					cl.SaveCrew();
					break;
				//add flight
				case 4:

					fl.AddFlight();
					fl.SaveFlight();
					break;
				//edit flight
				case 5:

					fl.EditFlight();
					fl.SaveFlight();
					break;
				//delete flight
				case 6:

					fl.DeleteFlight();
					fl.SaveFlight();
					break;
				//add plane
				case 7:

					pl.AddPlane();
					pl.SavePlane();
					break;
				//edit plane
				case 8:

					pl.EditPlane();
					pl.SavePlane();
					
					break;
				//delete plane
				case 9:

					pl.DeletePlane();
					pl.SavePlane();
					break;
				//prints plane
				case 10:

					pl.PrintPlane();
					break;
				//prints all planes
				case 11:

					pl.PrintAllPlanes();
					break;
				//prints all crew
				case 12:

					cl.PrintAllCrew();
					break;
				//print a flight
				case 13:

					fl.PrintFlight();
					break;
				//print all flights
				case 14:

					fl.PrintAllFlights();
					break;
				//print a crew member's assignments
				case 15:

					fl.PrintCrewAssignments();
					break;
				//print a plane's assignments
				case 16:

					pl.PrintPlaneAssignments();
					break;
				//load
				case 17:

					fl.LoadFlight();
					pl.LoadPlane();
					cl.LoadCrew();
					break;
				//save
				case 18:

					fl.SaveFlight();
					pl.SavePlane();
					cl.SaveCrew();
					break;

				default:
					continue;

		}


	} while(mainMenu() != 0);

	fl.SaveFlight();
	pl.SavePlane();
	cl.SaveCrew();

}
