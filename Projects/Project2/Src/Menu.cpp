/*
 * Menu.cpp
 * This file contains supplemental menu code for project 2.
 * 
 * Written by           :   Jacob Slaton
 * Date Created         :   Apr 4, 2014
 * Last Date Modified   :   Apr 4, 2014
 *
 * <sources_go_here>
 */

#include "Menu.h"

void mainMenu()
{
	bool mainQuit = false;
	while (!mainQuit)
	{
		systemClear();
		cout << "Main Menu\n\n";
		cout << "[1] Interactive Box Test\n";
		cout << "[2] Interactive Prize Test\n";
		cout << "[3] Unit Test\n";
		cout << "[0] Quit\n\n";
		cout << "What would you like to do? ";		
		
		switch (getValidInput(3))
		{
			case 0:
				mainQuit = true;
				break;
			case 1:
				boxMenu();
				break;
			case 2:
				prizeMenu();
				break;
			case 3:
				unittest();
				pause();
				break;
			default: ;
		}
	}
	systemClear();
}

void boxMenu()
{
	Box myBox;
	string name;
	unsigned int value;
	bool boxQuit = false;
	while (!boxQuit)
	{
		systemClear();
		cout << "Box Menu\n\n";
		cout << "Box Number\t:\t" << myBox.getBoxNumber() << "\n";
		cout << "Box Color\t:\t" << myBox.getBoxColor() << "\n\n";
		cout << "[1] Add prize\n";
		cout << "[2] View prizes\n";
		cout << "[3] Remove prize\n";
		cout << "[4] Update box number\n";
		cout << "[5] Update box color\n";
		cout << "[6] View prize capacity\n";
		cout << "[7] View prize count\n";
		cout << "[0] Back to Main Menu\n\n";
		cout << "What would you like to do? ";

		switch (getValidInput(7))
		{
			case 0:
				boxQuit = true;
				break;
			case 1:
				systemClear();
				cout << "Please enter your prize's name: ";
				getline(cin, name);
				cout << "Please enter your prize's value: ";
				value = getValidInput(INT_MAX);
				myBox.addPrize(Prize(name, value));
				pause();
				break;
			case 2:
				systemClear();
				for (unsigned int i = 0; i < myBox.getPrizeCount(); ++i)
					cout << (i + 1) << "\t:\t" << (myBox.getPrize(i)).getPrizeName() << endl;
				pause();
				break;
			case 3:
				systemClear();
				//
				// Grader comments 2014.04.11
				// Removes zero-based prize but the view that it shows
				// is one-based. Deducted 5 points. Otherwise,
				// outstanding code.
				//
				cout << "Which prize would you like removed? ";
				myBox.removePrize(getValidInput(INT_MAX));
				pause();
				break;
			case 4:
				systemClear();
				cout << "What is your new box number? ";
				myBox.setBoxNumber(getValidInput(INT_MAX));
				pause();
				break;
			case 5:
				systemClear();
				cout << "What is your new box color? ";
				getline(cin, name);
				myBox.setBoxColor(name);
				pause();
				break;
			case 6:
				systemClear();
				cout << "Prize Capacity\t:\t" << myBox.getPrizeCapacity() << endl;
				pause();
				break;
			case 7:
				systemClear();
				cout << "Prize Count\t:\t" << myBox.getPrizeCount() << endl;
				pause();
				break;
			default: ;
		}
	}
	systemClear();
}

void prizeMenu()
{
	Prize myPrize;
	Prize myOtherPrize;
	string name;
	unsigned int value;
	bool prizeQuit = false;
	while (!prizeQuit)
	{
		systemClear();
		cout << "Prize Menu\n\n";
		cout << "[1] Change prize name\n";
		cout << "[2] Change prize value\n";
		cout << "[3] Compare two prizes\n";
		cout << "[0] Back to Main Menu\n\n";
		cout << "What would you like to do? ";

		switch (getValidInput(3))
		{
			case 0:
				prizeQuit = true;
				break;
			case 1:
				systemClear();
				cout << "Prize name\t:\t" << myPrize.getPrizeName() << endl;
				cout << "What is your new prize name? ";
				getline(cin, name);
				myPrize.setPrizeName(name);
				pause();
				break;
			case 2:
				systemClear();
				cout << "Prize value\t:\t" << myPrize.getPrizeValue() << endl;
				cout << "What is your new prize value? ";
				myPrize.setPrizeValue(getValidInput(INT_MAX));
				pause();
				break;
			case 3:
				systemClear();
				
				cout << "Please enter your first prize's name: ";
				getline(cin, name);
				myPrize.setPrizeName(name);
				cout << "Please enter your first prize's value: ";
				myPrize.setPrizeValue(getValidInput(INT_MAX));
				
				cout << "Please enter your second prize's name: ";
				getline(cin, name);
				cout << "Please enter your second prize's value: ";
				value = getValidInput(INT_MAX);
				myOtherPrize.setPrizeName(name);
				myOtherPrize.setPrizeValue(value);
				
				if (myPrize == myOtherPrize)
					cout << "The two prizes are the same." << endl;
				else
					cout << "The two prizes are not the same." << endl;
				
				pause();
				break;
			default: ;
		}
	}
	systemClear();
}

int getValidInput(unsigned int max)
{
	while (true)
	{
		unsigned int inputAsInt = 0;
		string inputAsString;
		
		getline(cin, inputAsString);		
		inputAsInt = strtol(inputAsString.c_str(), NULL, 0);
		
		if (inputAsString == "0")
			return 0;
		
		if ((0 < inputAsInt) && (inputAsInt <= max))
			return inputAsInt;
		else
			cout << "Invalid input." << endl;
	}
	return -1;
}

void systemClear()
{
#ifdef WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pause()
{
	cout << "(Press enter to continue) " << endl;
	string dummy;
	getline(cin, dummy);
}
