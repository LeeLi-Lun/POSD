INC_DIR = include

all: hw2

hw2: main.o mainAtom.o atom.o mainVariable.o variable.o mainNumber.o number.o
	g++ -o hw2 main.o mainAtom.o atom.o mainVariable.o variable.o mainNumber.o number.o  -lgtest -lpthread

main.o: main.cpp utTerm.h
	g++ --std=c++11  main.cpp

utAtom: mainAtom.o atom.o
	g++ -o utAtom mainAtom.o  atom.o  -lgtest -lpthread
mainAtom.o: mainAtom.cpp utAtom.h
	g++ --std=c++11  mainAtom.cpp
atom.o: $(INC_DIR)/atom.h atom.cpp 
	g++ --std=c++11  atom.cpp

utVariable: mainVariable.o variable.o
		g++ -o utVariable mainVariable.o variable.o -lgtest -lpthread
mainVariable.o: mainVariable.cpp utVariable.h
		g++ --std=c++11   mainVariable.cpp
variable.o: $(INC_DIR)/variable.h variable.cpp 
		g++ --std=c++11   variable.cpp

utNumber: mainNumber.o number.o
		g++ -o utNumber mainNumber.o number.o -lgtest -lpthread
mainNumber.o: mainNumber.cpp utNumber.h
		g++ --std=c++11   mainNumber.cpp
number.o: $(INC_DIR)/number.h number.cpp 
		g++ --std=c++11   number.cpp

clean:
	rm -f *.o hw2 utAtom utNumber utVariable
stat:
	wc *.h *.cpp
