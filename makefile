main: main.o crews.o crew.o planes.o plane.o flight.o flights.o pilot.o copilot.o cabin.o
	g++ -o main main.o crews.o crew.o planes.o plane.o flight.o flights.o pilot.o copilot.o cabin.o

main.o: plane.h flight.h crew.h
	g++  -c main.cpp

crews.o: crew.h
	g++ -c crews.cpp

crew.o: 
	g++ -c crew.cpp

plane.o: 
	g++ -c plane.cpp

planes.o: plane.h
	g++ -c planes.cpp

flights.o: flight.h
	g++ -c flights.cpp

flight.o: crew.h
	g++ -c flight.cpp

pilot.o: crew.h
	g++ -c pilot.cpp crew.cpp

copilot.o: crew.h
	g++ -c copilot.cpp crew.cpp

cabin.o: crew.h
	g++ -c cabin.cpp crew.cpp

clean:
	rm *.o main

run:
	./main

#deletes data files
cleand:
	rm *.data

server_compile:
	g++ *.cpp -o main


