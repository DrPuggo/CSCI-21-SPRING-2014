# Makefile for pc27
#
# CSCI 21, Spring 2014
#
# Programmer: Jacob Slaton
#

FLAGS = -Wall -Wextra -Werror -pedantic -Wno-newline-eof

# Target for project 27
# Date completed: 5-12-2014
pc27: BSTNode.o BSTree.o pc27.cpp
	g++ $(FLAGS) BSTNode.o BSTree.o pc27.cpp -o pc27

BSTNode.o: BSTNode.h BSTNode.cpp
	g++ $(FLAGS) -c BSTNode.cpp -o BSTNode.o

BSTree.o: BSTree.h BSTree.cpp
	g++ $(FLAGS) -c BSTree.cpp -o BSTree.o
