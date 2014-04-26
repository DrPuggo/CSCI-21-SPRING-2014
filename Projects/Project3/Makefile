# Makefile for project 3
#
# CSCI 21, Spring 2014
#
# Programmer: Jacob Slaton
#

FLAGS = -Wall -Wextra -Werror -pedantic

# Target for project 3
release: Temp/DLNode.o Temp/DLList.o Temp/project3.o
	g++ $(FLAGS) Temp/DLNode.o Temp/DLList.o Temp/project3.o -o Exec/project3

clean:
	rm -f Temp/*

cleanall: clean
	rm -f Exec/*

Temp/project3.o: Src/project3.cpp
	g++ $(FLAGS) -c Src/project3.cpp -o Temp/project3.o

Temp/DLList.o: Src/DLList.h Src/DLList.cpp
	g++ $(FLAGS) -c Src/DLList.cpp -o Temp/DLList.o

Temp/DLNode.o: Src/DLNode.h Src/DLNode.cpp
	g++ $(FLAGS) -c Src/DLNode.cpp -o Temp/DLNode.o
