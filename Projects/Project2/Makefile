# Makefile for project 2
#
# CSCI 21, Spring 2014
#
# Programmer: Jacob Slaton
#

FLAGS = -Wall -Wextra -Werror -pedantic

# Target for project 2
release: Temp/Menu.o Temp/Prize.o Temp/Box.o Temp/project2.o
	g++ $(FLAGS) Src/project2.cpp Temp/Box.o Temp/Prize.o Temp/Menu.o -o Exec/project2

# Target for project 2 debug
debug: Temp/Menu.o Temp/Prize.o Temp/Box.o Temp/main.o
	g++ $(FLAGS) Src/main.cpp Temp/Box.o Temp/Prize.o Temp/Menu.o -o Exec/project2_debug

clean:
	rm -f Temp/*

cleanall: clean
	rm -f Exec/*

Temp/project2.o: Src/project2.cpp
	g++ $(FLAGS) -c Src/project2.cpp -o Temp/project2.o

Temp/main.o: Src/main.cpp
	g++ $(FLAGS) -c Src/main.cpp -o Temp/main.o

Temp/Box.o: Src/Box.h Src/Box.cpp
	g++ $(FLAGS) -c Src/Box.cpp -o Temp/Box.o

Temp/Prize.o: Src/Prize.h Src/Prize.cpp
	g++ $(FLAGS) -c Src/Prize.cpp -o Temp/Prize.o

Temp/Menu.o: Src/Menu.h Src/Menu.cpp
	g++ $(FLAGS) -c Src/Menu.cpp -o Temp/Menu.o
