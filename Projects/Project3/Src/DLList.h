/*
 * DLList.cpp
 * <description_here>
 *
 * Version				:	0.0.0
 * Author				:	Jacob Slaton
 * Date Created			:	Apr 19, 2014
 * Last Date Modified	:	Apr 19, 2014
 */

#pragma once

#include <iostream>
#include "DLNode.h"
using std::ostream;

//
// Grader comments 2014.05.14
// Ignore this stuff; I added it just to get the unit test
// to compile. Also added const to all your get... functions
// for the same reason.
//
#define head mHead
#define tail mTail
#define size mNodeCount

class DLList
{
	unsigned int mNodeCount;
	DLNode* mHead;
	DLNode* mTail;
public:
    /*
     * Constructor for DLList. Simply initializes the member variables.
     */
	DLList();

    /*
     * Deletes the list.
     */
	virtual ~DLList();

    /*
     * Returns the number of nodes in the list.
     * @return the number of nodes in the list
     */
	unsigned int getSize() const;
	
    /*
     * Inserts a new node in the list at the head.
     * @param contents the data to be stored in the list
     */
	void pushFront(int contents);

    /*
     * Inserts a new node in the list at the tail.
     * @param contents the data to be stored in the list
     */
	void pushBack(int contents);
	
    /*
     * Inserts a new node in the list so that
	 * the list is organized in ascending order.
     * @param contents the data to be stored in the list
     */
	void insert(int contents);
	
	int getFront() const;
	int getBack() const;
	bool get(int target) const;
	void popFront();
	void popBack();
	bool removeFirst(int target);
	bool removeAll(int target);
	
    /*
     * Deletes the contents of the list and sets mHead and mTail to NULL;
     */
	void clear();
	
    /*
     * Inserts the contents of the list in the output stream without a line break.
     * @param out the output stream that is being used
	 * @param src the list whose contents will be used
	 * @return out with the contents of the stream inserted without a line break
     */
	friend ostream& operator <<(ostream& out, const DLList& src);
protected:
private:
};
