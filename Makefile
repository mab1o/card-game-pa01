# Makefile
CXX_FLAG = --std=c++11 -g

all: game tests

game: cards.o utility.o main.o cardsbst.o
	g++ $(CXX_FLAG) -o game cards.o utility.o main.o cardsbst.o

tests: cards.o utility.o tests.o cardsbst.o
	g++ $(CXX_FLAG) -o tests cards.o utility.o tests.o cardsbst.o

cards.o: cards.cpp
	g++ -c $(CXX_FLAG) cards.cpp

utility.o: utility.cpp
	g++ -c $(CXX_FLAG) utility.cpp

tests.o: tests.cpp
	g++ -c $(CXX_FLAG) tests.cpp

main.o: main.cpp
	g++ -c $(CXX_FLAG) main.cpp

cardsbst.o : cardsbst.cpp
	g++ -c $(CXX_FLAG) cardsbst.cpp

clean:
	rm -f game *.o
	rm -f tests *.o
