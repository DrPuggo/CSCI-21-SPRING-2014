# Makefile for pc20
#
# CSCI 21, Spring 2014
#
# Programmer: Jacob Slaton
#

FLAGS = -Wall -Wextra -Werror -pedantic -Wno-newline-eof

# Target for project 19
# Date completed: 4-14-2014
pc18: SLNode.o SList.o pc20.cpp
	g++ $(FLAGS) SLNode.o SList.o pc20.cpp -o pc20

SList.o: SList.h SList.cpp
	g++ $(FLAGS) -c SList.cpp -o SList.o

SLNode.o: SLNode.h SLNode.cpp
	g++ $(FLAGS) -c SLNode.cpp -o SLNode.o
