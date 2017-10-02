all: hw2

hw2: Term.o Number.o Atom.o Variable.o
ifeq (${OS}, Windows_NT)
	g++ -o hw2 Term.o Number.o Atom.o Variable.o -lgtest
else
	g++ -o hw2 Term.o Number.o Atom.o Variable.o -lgtest -lpthread
endif
	
Term.o: Term.cpp utTerm.h 
	g++ -std=gnu++0x -c Term.cpp
Number.o: Number.cpp  
	g++ -std=gnu++0x -c Number.cpp
Atom.o: Atom.cpp
	g++ -std=gnu++0x -c Atom.cpp
Variable.o: Variable.cpp
	g++ -std=gnu++0x -c Variable.cpp

clean:	
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o hw2
endif
