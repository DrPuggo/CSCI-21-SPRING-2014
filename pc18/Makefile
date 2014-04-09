# Makefile for pc18
#
# CSCI 21, Spring 2014
#
# Programmer: Jacob Slaton
#

FLAGS = -Wall -Wextra -Werror -pedantic

# Target for project 18
# Date completed: 4-9-2014
pc18: SLNode.o SList.o pc18.cpp
	g++ $(FLAGS) SLNode.o SList.o pc18.cpp -o pc18

SList.o: SList.h SList.cpp
	g++ $(FLAGS) -c SList.cpp -o SList.o

SLNode.o: SLNode.h SLNode.cpp
	g++ $(FLAGS) -c SLNode.cpp -o SLNode.o
