all: hw5

hw5: main.o term.o
ifeq (${OS}, Windows_NT)
	g++ -o hw5 main.o  term.o -lgtest
else
	g++ -o hw5 main.o  term.o -lgtest -lpthread
endif

main.o: main.cpp
	g++ -std=gnu++0x -c main.cpp
term.o: main.cpp
	g++ -std=gnu++0x -c term.cpp

clean:
	rm -f *.o  hw5
stat:
	wc *.h *.cpp
