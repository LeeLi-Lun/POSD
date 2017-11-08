all: hw5 utAtom utVariable utNumber utStruct utList

hw5: mainScanner.o atom.o
ifeq (${OS}, Windows_NT)
	g++ -o hw5 mainScanner.o atom.o -lgtest
else
	g++ -o hw5 mainScanner.o atom.o -lgtest -lpthread
endif

utAtom: mainAtom.o atom.o
ifeq (${OS}, Windows_NT)
		g++ -o utAtom mainAtom.o atom.o -lgtest
else
		g++ -o utAtom mainAtom.o atom.o -lgtest -lpthread
endif

mainAtom.o: mainAtom.cpp utAtom.h atom.h utStruct.h struct.h
	g++ --std=gun++0x -c mainAtom.cpp

atom.o: atom.cpp atom.h variable.h
	g++ --std=gun++0x -c atom.cpp

utVariable: mainVariable.o atom.o
ifeq (${OS}, Windows_NT)
			g++ -o utVariable mainVariable.o atom.o -lgtest
else
			g++ -o utVariable mainVariable.o atom.o -lgtest -lpthread
endif

mainVariable.o: mainVariable.cpp utVariable.h variable.h
		g++ --std=gun++0x -c mainVariable.cpp

utScanner: mainScanner.o atom.o scanner.h utScanner.h utParser.h parser.h list.h
ifeq (${OS}, Windows_NT)
			g++ -o utScanner mainScanner.o atom.o -lgtest
else
			g++ -o utScanner mainScanner.o atom.o -lgtest -lpthread
endif

mainScanner.o: mainScanner.cpp utScanner.h scanner.h  atom.h struct.h variable.h  utParser.h parser.h list.h
	g++ --std=gun++0x -c mainScanner.cpp



clean:
	rm -f *.o  hw5 utAtom utVariable utNumber utStruct utList
stat:
	wc *.h *.cpp
