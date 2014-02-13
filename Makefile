# Makefile for programming challenges and projects
#
# CSCI 21, Spring 2014
#
# Programmer: Jacob Slaton
#

FLAGS = -Wall -Wextra -Werror -pedantic

all: project1 pc1 pc2 pc3 pc4 pc5

pc: pc1 pc2 pc3 pc4 pc5 pc6

# Target for project 1
# Date completed: 2-5-2014
project1: project1.cpp
	g++ $(FLAGS) project1.cpp -o project1.exe

# Target for programming challenge 1
# Date completed: 1-29-2014
pc1: pc1.cpp
	g++ $(FLAGS) pc1.cpp -o pc1.exe

# Target for programming challenge 2
# Date completed: 1-29-2014
pc2: pc2.cpp
	g++ $(FLAGS) pc2.cpp -o pc2.exe

# Target for programming challenge 3
# Date completed: 2-3-2014
pc3: pc3.cpp
	g++ $(FLAGS) pc3.cpp -o pc3.exe

# Target for programming challenge 4
# Date completed: 2-5-2014
pc4: pc4.cpp
	g++ $(FLAGS) pc4.cpp -o pc4.exe

# Target for programming challenge 5
# Date completed: 2-10-2014
pc5: pc5.cpp
	g++ $(FLAGS) pc5.cpp -o pc5.exe

# Target for programming challenge 6
# Date completed: 2-12-2014
pc6: pc6.cpp
	g++ $(FLAGS) pc6.cpp -o pc6.exe