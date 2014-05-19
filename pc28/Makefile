# Makefile for pc28
#
# CSCI 21, Spring 2014
#
# Programmer: Jacob Slaton
#

FLAGS = -Wall -Wextra -Werror -pedantic -Wno-newline-eof

# Target for project 28
# Date completed: 5-19-2014
pc28: MagicItem.o FoodItem.o pc28.cpp
	g++ $(FLAGS) MagicItem.o FoodItem.o Item.o pc28.cpp -o pc28

Item.o: Item.h Item.cpp
	g++ $(FLAGS) -c Item.cpp -o Item.o

FoodItem.o: Item.o FoodItem.h FoodItem.cpp
	g++ $(FLAGS) -c FoodItem.cpp -o FoodItem.o

MagicItem.o: Item.o MagicItem.h MagicItem.cpp
	g++ $(FLAGS) -c MagicItem.cpp -o MagicItem.o
