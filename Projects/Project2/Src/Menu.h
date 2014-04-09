/*
 * Menu.h
 * This file contains supplemental menu code for project 2.
 * 
 * Written by           :   Jacob Slaton
 * Date Created         :   Apr 4, 2014
 * Last Date Modified   :   Apr 4, 2014
 *
 * <sources_go_here>
 */

#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>
#include "Box.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;

void unittest();

/*
 * This handles all of the interactive tests for project 2,
 * and the unit test.
 */
void mainMenu();

/*
 * This handles the box menu for project 2.
 * It allows the user to interactively test the box class.
 */
void boxMenu();

/*
 * This handles the prize menu for project 2.
 * It allows the user to interactively test the prize class.
 */
void prizeMenu();

/*
 * This function prompts the user for input
 * and tests to make sure that input is an
 * unsigned int and does not exceed max.
 * @param max the highest desired input
 * @return an unsigned int between (or equal to) 0 and max
 */
int getValidInput(unsigned int max);

/*
 * This function clears the console screen.
 * This function has been tested on Windows and Linux.
 */
void systemClear();

/*
 * This function waits for the
 * user to press the enter key.
 */
void pause();
