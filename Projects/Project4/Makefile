# Makefile for project 4
#
# CSCI 21, Spring 2014
#
# Programmer: Jacob Slaton
#

FLAGS = -Wall -Wextra -Werror -pedantic

debug: Temp/Word.o Src/BSTNode.h Src/BSTree.h Src/debug.cpp
	g++ $(FLAGS) Temp/Word.o Src/debug.cpp -o Exec/debug

release: Temp/Word.o Src/BSTNode.h Src/BSTree.h Src/project4.cpp
	g++ $(FLAGS) Temp/Word.o Src/project4.cpp -o Exec/project4

clean:
	rm -f Temp/*

cleanall: clean
	rm -f Exec/*

Temp/Word.o: Src/Word.h Src/Word.cpp
	g++ $(FLAGS) -c Src/Word.cpp -o Temp/Word.o
