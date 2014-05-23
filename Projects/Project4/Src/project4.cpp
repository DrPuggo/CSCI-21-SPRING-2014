//
// Grader comments 2014.05.22
// -55 points total
//
/*
 * Programming Project 4
 * This driver tests the classes BSTree, BSTNode,
 * and Word for correct functionality.
 * 
 * Jacob Slaton
 * Date Created: May 16, 2014
 * Last Date Modified: May 16, 2014
 */

#include <iostream>
#include <fstream>
#include "BSTree.h"
#include "Word.h"
using std::fstream;

int main(int argc, char* argv[])
{
    fstream fin;
	string script;
	string wordFromScript;
	Word* word = NULL;
    BSTree<Word>* tree = NULL;
    
    if (argc < 2)
	{
		cout << "Usage: project4 FILENAME" << endl;
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
    	        if (tree)
    	        {
    	            delete tree;
    	            tree = NULL;
    	        }
	            tree = new BSTree<Word>();
	            cout << "TREE CREATED" << endl;
    	        break;
		    case 'X':
		        if (!tree)
		        {
		            cout << "MUST CREATE TREE INSTANCE" << endl;
		            break;
		        }
		        tree->clear();
		        cout << "TREE CLEARED" << endl;
		        break;
		    case 'D':
			//
			// Grader comments 2014.05.22
			// Need to say "MUST CREATE TREE INSTANCE" if the
			// tree doesn't exist.
			// -5 points
			//
    	        if (tree)
    	        {
    	            delete tree;
    	            tree = NULL;
		            cout << "TREE DELETED" << endl;
    	        }
				else	// Rob added to get unit test to run
				{
					cout << "MUST CREATE TREE INSTANCE" << endl;
				}
		        break;
		    case 'I':
		        if (!tree)
		        {
		            cout << "MUST CREATE TREE INSTANCE" << endl;
		            break;
		        }
				//
				// Grader comments 2014.05.22
				// You're chopping off the last character of the
				// word to be inserted.
				// -10 points
				//
		        //wordFromScript = script.substr(2, (script.length() - 3));	// Rob
				wordFromScript = script.substr(2, (script.length() - 2));	// Rob
		      //  wordFromScript[wordFromScript.length() - 1] = ' ';
		        if (tree->insert(wordFromScript) == true)
		            cout << "WORD " << wordFromScript << " INSERTED" << endl;
		        else
		        {
		            word = NULL;
		            word = tree->get(Word(wordFromScript));
		            if (word)
		            {
		                word->incrementCount();
    		            cout << "WORD " << wordFromScript << " INCREMENTED" << endl;
		            }
		        }
		        break;
		    case 'F':
		        if (!tree)
		        {
		            cout << "MUST CREATE TREE INSTANCE" << endl;
		            break;
		        }
		        if (tree->getSize() == 0)
		        {
		            cout << "TREE EMPTY" << endl;
		            break;
		        }
				//
				// Grader comments 2014.05.22
				// You're chopping off the last character of the
				// word to be inserted.
				// -10 points
				//
		        //wordFromScript = script.substr(2, (script.length() - 3));	// Rob
				wordFromScript = script.substr(2, (script.length() - 2));	// Rob
		        if (tree->find(wordFromScript))
		            cout << "FOUND " << wordFromScript << endl;
		        else
		            cout << wordFromScript << " NOT FOUND" << endl;
		        break;
		    case 'R':
		        if (!tree)
		        {
		            cout << "MUST CREATE TREE INSTANCE" << endl;
		            break;
		        }
		        if (tree->getSize() == 0)
		        {
		            cout << "TREE EMPTY" << endl;
		            break;
		        }
				//
				// Grader comments 2014.05.22
				// You're chopping off the last character of the
				// word to be inserted.
				// -10 points
				//
		        //wordFromScript = script.substr(2, (script.length() - 3));	// Rob
				wordFromScript = script.substr(2, (script.length() - 2));	// Rob
		        if (tree->remove(wordFromScript))
		            cout << "REMOVED " << wordFromScript << endl;
		        else
		            cout << wordFromScript << " NOT FOUND" << endl;
		        break;
		    case 'G':
		        if (!tree)
		        {
		            cout << "MUST CREATE TREE INSTANCE" << endl;
		            break;
		        }
		        if (tree->getSize() == 0)
		        {
		            cout << "TREE EMPTY" << endl;
		            break;
		        }
				//
				// Grader comments 2014.05.22
				// You're chopping off the last character of the
				// word to be inserted.
				// -10 points
				//
		        //wordFromScript = script.substr(2, (script.length() - 3));	// Rob
				wordFromScript = script.substr(2, (script.length() - 2));	// Rob
		        word = NULL;
		        word = tree->get(wordFromScript);
		        if (word)
		            cout << "GOT " << *word << endl;
		        else
		            cout << wordFromScript << " NOT FOUND" << endl;
		        break;
		    case 'N':
		        if (!tree)
		        {
		            cout << "MUST CREATE TREE INSTANCE" << endl;
		            break;
		        }
		        cout << "TREE SIZE IS " << tree->getSize() << endl;
		        break;
		    case 'O':
		        if (!tree)
		        {
		            cout << "MUST CREATE TREE INSTANCE" << endl;
		            break;
		        }
				//
				// Grader comments 2014.05.22
				// Need to report empty tree if necessary
				// -5 points
				//
		        else if (tree->getSize() == 0)
		        {
		            cout << "TREE EMPTY" << endl;
		            break;
		        }
				else
				{
					tree->inOrder();
			        break;
				}
		    case 'E':
		        if (!tree)
		        {
		            cout << "MUST CREATE TREE INSTANCE" << endl;
		            break;
		        }
				//
				// Grader comments 2014.05.22
				// Need to report empty tree if necessary
				// -5 points
				//
		        else if (tree->getSize() == 0)
		        {
		            cout << "TREE EMPTY" << endl;
		            break;
		        }
				else
				{
					tree->reverseOrder();
		        	break;
				}
		    default: ;
		}
	}
	
	fin.close();
	if (!tree)
		delete tree;
	tree = NULL;

    return 0;
}
