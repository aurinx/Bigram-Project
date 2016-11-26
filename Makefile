#Makefile for A7

all: a7a a7b

a7a: a7a.cpp
	g++ -Wall -Wextra -pedantic -std=c++11 -g a7a.cpp -o a7a

a7b: a7b.cpp
	g++ -Wall -Wextra -pedantic -std=c++11 -g a7b.cpp -o a7b

clean:
	rm -f a7a.o a7a
	rm -f a7b.o a7b
