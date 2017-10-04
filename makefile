INC_DIR = include

all: hw2

hw2: main.o mainAtom.o atom.o mainVariable.o variable.o mainNumber.o number.o
ifeq (${OS}, Windows_NT)
	g++ -o hw2 main.o mainAtom.o atom.o mainVariable.o variable.o mainNumber.o number.o  -lgtest 
else
	g++ -o hw2 main.o mainAtom.o atom.o mainVariable.o variable.o mainNumber.o number.o  -lgtest -lpthread
endif

main.o: main.cpp utTerm.h
	g++ --std=c++11  main.cpp

utAtom: mainAtom.o atom.o
ifeq (${OS}, Windows_NT)
	g++ -o utAtom mainAtom.o  atom.o  -lgtest 
else
	g++ -o utAtom mainAtom.o  atom.o  -lgtest -lpthread
endif
mainAtom.o: mainAtom.cpp utAtom.h
	g++ --std=c++11  mainAtom.cpp
atom.o: atom.cpp $(INC_DIR)/atom.h
	g++ --std=c++11  atom.cpp

utVariable: mainVariable.o variable.o
ifeq (${OS}, Windows_NT)
	g++ -o utVariable mainVariable.o variable.o -lgtest 
else
	g++ -o utVariable mainVariable.o variable.o -lgtest -lpthread
endif
mainVariable.o: mainVariable.cpp utVariable.h
		g++ --std=c++11  mainVariable.cpp
variable.o: variable.cpp $(INC_DIR)/variable.h
		g++ --std=c++11  variable.cpp

utNumber: mainNumber.o number.o
ifeq (${OS}, Windows_NT)
	g++ -o utNumber mainNumber.o number.o -lgtest 
else
	g++ -o utNumber mainNumber.o number.o -lgtest -lpthread
endif

mainNumber.o: mainNumber.cpp utNumber.h
		g++ --std=c++11  mainNumber.cpp
number.o: number.cpp $(INC_DIR)/number.h
		g++ --std=c++11  number.cpp

clean:
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o hw2 utAtom utNumber utVariable
endif

stat:
	wc *.h *.cpp

