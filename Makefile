all: main.o bunch.o
	g++ main.o bunch.o -o Lab6
	
main.o: main.cpp
	g++ -c main.cpp
	
bunch.o: bunch.cpp
	g++ -c bunch.cpp
	
clean:
	rm -rf *.o