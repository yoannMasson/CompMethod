all: matrix.o vector.o Analytic.o Solver.o Richardson.o Test.o Laasonen.o DufortFrankel.o CrankNicolson.o
	g++ matrix.o vector.o Analytic.o Solver.o Richardson.o Test.o Laasonen.o DufortFrankel.o CrankNicolson.o -o test

matrix.o: matrix.cpp
	g++ -c matrix.cpp

vector.o: vector.cpp
	g++ -c vector.cpp

Analytic.o: Analytic.cpp
	g++ -c Analytic.cpp

Solver.o: Solver.cpp
	g++ -c Solver.cpp
	
Richardson.o: Richardson.cpp
	g++ -c Richardson.cpp

Test.o: Test.cpp
	g++ -c Test.cpp

Laasonen.o: Laasonen.cpp
	g++ -c Laasonen.cpp
	
DufortFrankel.o: DufortFrankel.cpp
	g++ -c DufortFrankel.cpp
	
CrankNicolson.o: CrankNicolson.cpp
	g++ -c CrankNicolson.cpp
	
clean:
	rm -rf *.o
	rm test
