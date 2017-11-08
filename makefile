all: hw5 utAtom utVariable utNumber utStruct utList

hw5: mainScanner.o atom.o
ifeq (${OS}, Windows_NT)
	g++ -o hw5 mainScanner.o atom.o -lgtest
else
	g++ -o hw5 mainScanner.o atom.o -lgtest -lpthread
endif

utAtom: mainAtom.o atom.o
	g++ -o utAtom mainAtom.o atom.o -lgtest -lpthread
mainAtom.o: mainAtom.cpp utAtom.h atom.h utStruct.h struct.h
	g++ -std=gnu++0x -c mainAtom.cpp

atom.o: atom.cpp atom.h variable.h
	g++ -std=gnu++0x -c atom.cpp

utVariable: mainVariable.o atom.o
	g++ -o utVariable mainVariable.o atom.o -lgtest -lpthread
mainVariable.o: mainVariable.cpp utVariable.h variable.h
		g++ -std=gnu++0x -c mainVariable.cpp

utScanner: mainScanner.o atom.o scanner.h utScanner.h utParser.h parser.h list.h
	g++ -o utScanner mainScanner.o atom.o -lgtest -lpthread
mainScanner.o: mainScanner.cpp utScanner.h scanner.h  atom.h struct.h variable.h  utParser.h parser.h list.h
	g++ -std=gnu++0x -c mainScanner.cpp

clean:
	rm -f *.o  hw5 utAtom utVariable utNumber utStruct utList
stat:
	wc *.h *.cpp
