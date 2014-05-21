# Makefile for pc29
#
# CSCI 21, Spring 2014
#
# Programmer: Jacob Slaton
#

FLAGS = -Wall -Wextra -Werror -pedantic -Wno-newline-eof

# Target for project 29
# Date completed: 5-21-2014
pc29: TreasureChest.o pc29.cpp
	g++ $(FLAGS) TreasureChest.o pc29.cpp -o pc29

TreasureChest.o: TreasureChest.h TreasureChest.cpp
	g++ $(FLAGS) -c TreasureChest.cpp -o TreasureChest.o
