# Makefile for pc26
#
# CSCI 21, Spring 2014
#
# Programmer: Jacob Slaton
#

FLAGS = -Wall -Wextra -Werror -pedantic -Wno-newline-eof

# Target for project 26
# Date completed: 5-7-2014
pc26: BSTNode.o BSTree.o pc26.cpp
	g++ $(FLAGS) BSTNode.o BSTree.o pc26.cpp -o pc26

BSTNode.o: BSTNode.h BSTNode.cpp
	g++ $(FLAGS) -c BSTNode.cpp -o BSTNode.o

BSTree.o: BSTree.h BSTree.cpp
	g++ $(FLAGS) -c BSTree.cpp -o BSTree.o
