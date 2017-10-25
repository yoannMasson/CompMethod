all: matrix.o vector.o Analytic.o Solver.o Richardson.o Test.o
	g++ matrix.o vector.o Analytic.o Solver.o Richardson.o Test.o -o test

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

clean:
	rm -rf *.o
