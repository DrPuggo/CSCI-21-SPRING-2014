//
// Grader comments 2014.05.14
// + 50: naming conventions good
// + 50: header documentation good
// + 50: formatting good
// +137: driver -- see comments below; look for "grader comments" and "Rob"
// +150: DLNode good
// +200: DLList -- see comments DLList.cpp
// 
/*
 * Programming Project 3
 * This project interprets a script used to test a doubly linked list.
 * 
 * Written by			:	Jacob Slaton
 * Date Created			:	Apr 19, 2014
 * Last Date Modified	:	Apr 19, 2014
 *
 * <sources_go_here>
 */

#include <iostream>
#include <string>
#include <fstream>
#include "DLList.h"
using std::cout;
using std::endl;
using std::string;
using std::fstream;

//
// Grader comments 2014.05.15
// -  5: A & Z catch the wrong kind of exception from DLList.
// -  8: P doesn't print the list, but the list address.
//
int main(int argc, char* argv[])
{
	fstream fin;
	string script;
	int intFromScript = 0;
	DLList* list = NULL;

	if (argc < 2)
	{
		cout << "Usage: project3 FILENAME" << endl;
		return 0;
	}

	fin.open(argv[1]);
	
	if (fin.fail() == true)
	{
		cout << "Text file could not be opened." << endl;
		return 0;
	}
	
	while (getline(fin, script))
	{
		switch (script[0])
		{
			case 'C':
				if (list != NULL)
					delete list;
				list = new DLList();
				cout << "LIST CREATED" << endl;
				break;
			case 'X':
				if (list == NULL)
					cout << "MUST CREATE LIST INSTANCE" << endl;
				else
				{
					list->clear();
					cout << "LIST CLEARED" << endl;
				}
				break;
			case 'D':
				if (list == NULL)
					cout << "MUST CREATE LIST INSTANCE" << endl;
				else
				{
					delete list;
					list = NULL;
					cout << "LIST DELETED" << endl;
				}
				break;
			case 'I':
				if (list == NULL)
					cout << "MUST CREATE LIST INSTANCE" << endl;
				else
				{
					intFromScript = strtol((script.substr(2)).c_str(), NULL, 0);
					list->insert(intFromScript);
					cout << "VALUE " << intFromScript << " INSERTED" << endl;
				}
				break;
			case 'F':
				if (list == NULL)
					cout << "MUST CREATE LIST INSTANCE" << endl;
				else
				{
					intFromScript = strtol((script.substr(2)).c_str(), NULL, 0);
					list->pushFront(intFromScript);
					cout << "VALUE " << intFromScript << " ADDED TO HEAD" << endl;
				}
				break;
			case 'B':
				if (list == NULL)
					cout << "MUST CREATE LIST INSTANCE" << endl;
				else
				{
					intFromScript = strtol((script.substr(2)).c_str(), NULL, 0);
					list->pushBack(intFromScript);
					cout << "VALUE " << intFromScript << " ADDED TO TAIL" << endl;
				}
				break;
			case 'A':
				if (list == NULL)
					cout << "MUST CREATE LIST INSTANCE" << endl;
				else
				{
					try
					{
						intFromScript = list->getFront();
						cout << "VALUE " << intFromScript << " AT HEAD" << endl;
					}
					//catch (string e)		// Rob
					catch(char const* e)	// Rob
					{
						cout << e << endl;
					}
				}
				break;
			case 'Z':
				if (list == NULL)
					cout << "MUST CREATE LIST INSTANCE" << endl;
				else
				{
					try
					{
						intFromScript = list->getBack();
						cout << "VALUE " << intFromScript << " AT TAIL" << endl;
					}
					//catch (string e)		// Rob
					catch(char const* e)	// Rob
					{
						cout << e << endl;
					}
				}
				break;
			case 'T':
				if (list == NULL)
					cout << "MUST CREATE LIST INSTANCE" << endl;
				else if (list->getSize() == 0)
					cout << "LIST EMPTY" << endl;
				else
				{
					list->popFront();
					cout << "REMOVED HEAD" << endl;
				}
				break;
			case 'K':
				if (list == NULL)
					cout << "MUST CREATE LIST INSTANCE" << endl;
				else if (list->getSize() == 0)
					cout << "LIST EMPTY" << endl;
				else
				{
					list->popBack();
					cout << "REMOVED TAIL" << endl;
				}
				break;
			case 'E':
				if (list == NULL)
					cout << "MUST CREATE LIST INSTANCE" << endl;
				else
				{
					intFromScript = strtol((script.substr(2)).c_str(), NULL, 0);
					if (list->removeAll(intFromScript) == true)
						cout << "VALUE " << intFromScript << " ELIMINATED" << endl;
					else
						cout << "VALUE " << intFromScript << " NOT FOUND" << endl;
				}
				break;
			case 'R':
				if (list == NULL)
					cout << "MUST CREATE LIST INSTANCE" << endl;
				else
				{
					intFromScript = strtol((script.substr(2)).c_str(), NULL, 0);
					if (list->removeFirst(intFromScript) == true)
						cout << "VALUE " << intFromScript << " REMOVED" << endl;
					else
						cout << "VALUE " << intFromScript << " NOT FOUND" << endl;
				}
				break;
			case 'G':
				if (list == NULL)
					cout << "MUST CREATE LIST INSTANCE" << endl;
				else
				{
					intFromScript = strtol((script.substr(2)).c_str(), NULL, 0);
					if (list->get(intFromScript) == true)
						cout << "VALUE " << intFromScript << " FOUND" << endl;
					else
						cout << "VALUE " << intFromScript << " NOT FOUND" << endl;
				}
				break;
			case 'N':
				if (list == NULL)
					cout << "MUST CREATE LIST INSTANCE" << endl;
				else
					cout << "LIST SIZE IS " << list->getSize() << endl;
				break;
			case 'P':
				if (list == NULL)
					cout << "MUST CREATE LIST INSTANCE" << endl;
				else
					//cout << list << endl;	// Rob
					cout << *list << endl;	// Rob
				break;
			case '#':
			default:
				break;
		}
	}
	
	fin.close();
	if (list != NULL)
		delete list;
	list = NULL;
	return 0;
}
