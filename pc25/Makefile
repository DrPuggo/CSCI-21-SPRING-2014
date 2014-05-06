# Makefile for pc25
#
# CSCI 21, Spring 2014
#
# Programmer: Jacob Slaton
#

FLAGS = -Wall -Wextra -Werror -pedantic -Wno-newline-eof

# Target for project 25
# Date completed: 5-5-2014
pc25: BSTNode.o pc25.cpp
	g++ $(FLAGS) BSTNode.o pc25.cpp -o pc25

BSTNode.o: BSTNode.h BSTNode.cpp
	g++ $(FLAGS) -c BSTNode.cpp -o BSTNode.o
