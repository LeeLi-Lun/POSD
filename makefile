all: hw7 utIterator

hw7: mainIterator.o
ifeq (${OS}, Windows_NT)
	g++ -o hw7 mainIterator.o -lgtest
else
	g++ -o hw7 mainIterator.o -lgtest -lpthread
endif

atom.o: atom.cpp atom.h variable.h
	g++ -std=c++11 -c atom.cpp
list.o:list.cpp list.h
		g++ -std=c++11 -c list.cpp
struct.o:struct.cpp struct.h
		g++ -std=c++11 -c struct.cpp

utIterator: mainIterator.o atom.o list.o struct.o iterator.h utIterator.h
	g++ -o utIterator mainIterator.o atom.o list.o struct.o -lgtest -lpthread

mainIterator.o: mainIterator.cpp utIterator.h iterator.h
	g++ -std=c++11 -c mainIterator.cpp

clean:
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o hw7 utIterator
endif

stat:
	wc *.h *.cpp
