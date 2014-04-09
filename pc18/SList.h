#pragma once

#include <cstdlib>
#include <string>
#include <sstream>
#include "SLNode.h"
using std::string;
using std::stringstream;

class SList
{
    SLNode* mHead;
    unsigned int mNumNodes;
public:
    /*
     * Constructor for SList. Simply initializes the member variables.
     */
    SList();
    
    /*
     * Deletes the list.
     */
    virtual ~SList();
    
    /*
     * Inserts a new node in the list at the head.
     * @param value the data to be stored in the list\
     */
    void insertHead(int value);
    
    /*
     * Remove the node at the head (if it exists).
     */
    void removeHead();
    
    /*
     * Deletes the contents of the list and sets mHead to NULL;
     */
    void clear();
    
    /*
     * Returns the number of nodes in the list.
     * @return mNumNodes
     */
    unsigned int getSize();
    
    /*
     * Returns the contents of the list in the format "NUM1,NUM2,...,LASTNUM".
     * @return the list contents, or "" if mHead is NULL
     */
    string toString();
protected:
private:
};
