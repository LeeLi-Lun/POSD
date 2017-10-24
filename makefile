all: hw4 utAtom utVariable utNumber utStruct utList

hw4: main.o
ifeq (${OS}, Windows_NT)
	g++ -o hw4 main.o -lgtest
else
	g++ -o hw4 main.o -lgtest -lpthread
endif
main.o: main.cpp utTerm.h utAtom.h utVariable.h utNumber.h utList.h
	g++ -std=gnu++0x -c  main.cpp

utAtom: mainAtom.o
ifeq (${OS}, Windows_NT)
	g++ -o utAtom mainAtom.o -lgtest
else
	g++ -o utAtom mainAtom.o -lgtest -lpthread
endif
mainAtom.o: mainAtom.cpp utAtom.h t
	g++ -std=gnu++0x -c  mainAtom.cpp

utVariable: mainVariable.o
ifeq (${OS}, Windows_NT)
	g++ -o utVariable mainVariable.o -lgtest
else
	g++ -o utVariable mainVariable.o -lgtest -lpthread
endif
mainVariable.o: mainVariable.cpp utVariable.h
		g++ -std=gnu++0x -c  mainVariable.cpp

utNumber: mainNumber.o
ifeq (${OS}, Windows_NT)
	g++ -o utNumber mainNumber.o  -lgtest
else
	g++ -o utNumber mainNumber.o  -lgtest -lpthread
endif
mainNumber.o: mainNumber.cpp utNumber.h
		g++ -std=gnu++0x -c  mainNumber.cpp

utStruct: mainStruct.o
ifeq (${OS}, Windows_NT)
	g++ -o utStruct mainStruct.o  -lgtest
else
	g++ -o utStruct mainStruct.o  -lgtest -lpthread
endif
mainStruct.o: mainStruct.cpp utStruct.h
		g++ -std=gnu++0x -c  mainStruct.cpp

utTerm: mainTerm.o
ifeq (${OS}, Windows_NT)
	g++ -o utTerm mainTerm.o  -lgtest
else
	g++ -o utTerm mainTerm.o  -lgtest -lpthread
endif
mainTerm.o: mainTerm.cpp utTerm.h
		g++ -std=gnu++0x -c  mainTerm.cpp

utList: mainList.o
ifeq (${OS}, Windows_NT)
	g++ -o utList mainList.o  -lgtest
else
	g++ -o utList mainList.o  -lgtest -lpthread
endif
mainList.o: mainList.cpp utList.h list.h
		g++ -std=gnu++0x -c  mainList.cpp

clean:
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o hw* utAtom utNumber utVariable utStruct utTerm utList
endif

stat:
	wc *.h *.cpp
