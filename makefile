all: hw2

hw2: main.o mainAtom.o atom.o mainVariable.o variable.o mainNumber.o number.o
ifeq (${OS}, Windows_NT)
	g++ -o hw2 main.o mainAtom.o atom.o mainVariable.o variable.o mainNumber.o number.o  -lgtest 
else
	g++ -o hw2 main.o mainAtom.o atom.o mainVariable.o variable.o mainNumber.o number.o  -lgtest -lpthread
endif

main.o: main.cpp utTerm.h
	g++ -std=gnu++0x -c  main.cpp

utAtom: mainAtom.o atom.o
ifeq (${OS}, Windows_NT)
	g++ -o utAtom mainAtom.o  atom.o  -lgtest 
else
	g++ -o utAtom mainAtom.o  atom.o  -lgtest -lpthread
endif
mainAtom.o: mainAtom.cpp utAtom.h
	g++ -std=gnu++0x -c  mainAtom.cpp
atom.o: atom.cpp atom.h
	g++ -std=gnu++0x -c  atom.cpp

utVariable: mainVariable.o variable.o
ifeq (${OS}, Windows_NT)
	g++ -o utVariable mainVariable.o variable.o -lgtest 
else
	g++ -o utVariable mainVariable.o variable.o -lgtest -lpthread
endif
mainVariable.o: mainVariable.cpp utVariable.h
		g++ -std=gnu++0x -c  mainVariable.cpp
variable.o: variable.cpp variable.h
		g++ -std=gnu++0x -c  variable.cpp

utNumber: mainNumber.o number.o
ifeq (${OS}, Windows_NT)
	g++ -o utNumber mainNumber.o number.o -lgtest 
else
	g++ -o utNumber mainNumber.o number.o -lgtest -lpthread
endif

mainNumber.o: mainNumber.cpp utNumber.h
		g++ -std=gnu++0x -c  mainNumber.cpp
number.o: number.cpp number.h
		g++ -std=gnu++0x -c  number.cpp

clean:
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o hw2 utAtom utNumber utVariable
endif

stat:
	wc *.h *.cpp

