# Makefile
CXX_FLAG = --std=c++11 -g

all: game

game:  cards.o utility.o main.o run_test
	g++ $(CXX_FLAG) -o game cards.o utility.o main.o

tests: cards.o utility.o tests.o
	g++ $(CXX_FLAG) -o tests cards.o utility.o tests.o

run_test : tests
	./tests

cards.o: cards.cpp
	g++ -c $(CXX_FLAG) cards.cpp

utility.o: utility.cpp
	g++ -c $(CXX_FLAG) utility.cpp

tests.o: tests.cpp
	g++ -c $(CXX_FLAG) tests.cpp

main.o: main.cpp
	g++ -c $(CXX_FLAG) main.cpp

clean:
	rm -f game *.o
	rm -f tests *.o
