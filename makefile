INC_DIR = include

all: hw2

hw2: main.o mainAtom.o atom.o mainVariable.o variable.o mainNumber.o number.o
	g++ -o hw2 main.o mainAtom.o atom.o mainVariable.o variable.o mainNumber.o number.o  -lgtest -lpthread

main.o: main.cpp utTerm.h
	g++ -std=c++11 -c main.cpp

utAtom: mainAtom.o atom.o
	g++ -o utAtom mainAtom.o  atom.o  -lgtest -lpthread
mainAtom.o: mainAtom.cpp utAtom.h
	g++ -std=c++11 -c mainAtom.cpp
atom.o: atom.cpp $(INC_DIR)/atom.h
	g++ -std=c++11 -c atom.cpp

utVariable: mainVariable.o variable.o
		g++ -o utVariable mainVariable.o variable.o -lgtest -lpthread
mainVariable.o: mainVariable.cpp utVariable.h
		g++ -std=c++11 -c mainVariable.cpp
variable.o: variable.cpp $(INC_DIR)/variable.h
		g++ -std=c++11 -c variable.cpp

utNumber: mainNumber.o number.o
		g++ -o utNumber mainNumber.o number.o -lgtest -lpthread
mainNumber.o: mainNumber.cpp utNumber.h
		g++ -std=c++11 -c mainNumber.cpp
number.o: number.cpp $(INC_DIR)/number.h
		g++ -std=c++11 -c number.cpp

clean:
	rm -f *.o hw2 utAtom utNumber utVariable
stat:
	wc *.h *.cpp
