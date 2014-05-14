//
// Grader comments 2014.05.13
// -75 points total
//

/*
 * DLList.cpp
 * <description_here>
 *
 * Version				:	0.0.0
 * Author				:	Jacob Slaton
 * Date Created			:	Apr 19, 2014
 * Last Date Modified	:	Apr 19, 2014
 */

#include "DLList.h"

DLList::DLList()
: mNodeCount(0), mHead(NULL), mTail(NULL)
{
}

DLList::~DLList()
{
	clear();
}

unsigned int DLList::getSize() const
{
	return mNodeCount;
}

//
// Grader comments 2014.05.14
// Previous link never set when inserting new node. Causes
// intermittent crashing.
// -10 points
//
void DLList::pushFront(int contents)
{
    DLNode* temp = new DLNode(contents);
    temp->setNext(mHead);
	if (mTail == NULL)
		mTail = temp;
	
	if(mHead != NULL) {	// Rob
		mHead->setPrevious(temp);
	}
    mHead = temp;
    ++mNodeCount;
}

//
// Grader comments 2014.05.14
// Points new node in the wrong direction.
// Doesn't point the old tail to the new tail.
// -15 points
//
void DLList::pushBack(int contents)
{
    DLNode* temp = new DLNode(contents);
    //temp->setPrevious(mHead);				// Rob
	temp->setPrevious(mTail);				// Rob
	if (mHead == NULL)
		mHead = temp;
	
	if(mTail != NULL) {						// Rob
		mTail->setNext(temp);
	}
	
    mTail = temp;
    ++mNodeCount;
}

void DLList::insert(int contents)
{
	if (mHead == NULL)
	{
		pushFront(contents);
		return;
	}
	if (mTail == NULL)
	{
		if (contents < mHead->getContents())
		{
			pushFront(contents);
			return;
		}
		pushBack(contents);
		return;
	}
	DLNode* spot = mHead;
	DLNode* trailer = NULL;
	while ((spot->getNext() != NULL) && (contents > spot->getContents()))
	{
		trailer = spot;
		spot = spot->getNext();
	}
	DLNode* temp = new DLNode(contents);
	temp->setNext(spot);
	temp->setPrevious(trailer);
	if (trailer != NULL)
		trailer->setNext(temp);
	++mNodeCount;
}

int DLList::getFront() const
{
	if (mHead == NULL)
		throw "LIST EMPTY";
	return mHead->getContents();
}

int DLList::getBack() const
{
	if (mTail == NULL)
		throw "LIST EMPTY";
	return mTail->getContents();
}

//
// Grader comments 2014.05.14
// Misses the last item on the list.
// -5 points
bool DLList::get(int target) const
{
	if (mHead == NULL)
		return false;
	DLNode* temp = mHead;
	//while ((temp != NULL) && (temp->getNext()))	// Rob
	while(temp != NULL)								// Rob
	{
		if (temp->getContents() == target)
			return true;
		temp = temp->getNext();
	}
	return false;
}

//
// Grader comments 2014.05.14
// Attempts to set previous link even when there is no more list.
// Doesn't manage node count.
// Doesn't always manage tail when necessary.
// -15 points
//
void DLList::popFront()
{
	if (mHead == NULL)
		return;
	DLNode* temp = mHead;
	if (mTail == mHead)
		mTail = NULL;
	mHead = mHead->getNext();
	
	if(mHead != NULL) {				// Rob
		mHead->setPrevious(NULL);
	}
	
	delete temp;
	
	--mNodeCount;					// Rob
	if(mNodeCount == 1) {			// Rob
		mTail = mHead;
	}
}

//
// Grader comments 2014.05.14
// Attempts to set next link even when there is no more list.
// Doesn't manage node count.
// Doesn't always manage head when necessary.
// -15 points
//
void DLList::popBack()
{
	if (mTail == NULL)
		return;
	DLNode* temp = mTail;
	if (mHead == mTail)
		mHead = NULL;
	mTail = mTail->getPrevious();
	
	if(mTail != NULL) {				// Rob
		mTail->setNext(NULL);
	}
	
	delete temp;
	
	--mNodeCount;					// Rob
	if(mNodeCount == 1) {			// Rob
		mHead = mTail;
	}
}

//
// Grader comments 2014.05.14
// Doesn't manage tail when necessary.
// Doesn't insert new node properly.
// -15 points.
//
bool DLList::removeFirst(int target)
{
	if (mHead == NULL)
		return false;
	
	DLNode* spot = mHead;
	DLNode* trailer = NULL;
	while ((spot != NULL) && (spot->getContents() != target))
	{
		trailer = spot;
		spot = spot->getNext();
	}
	
	if (spot == NULL)
	{
		return false;
	}
	else if (spot == mHead)
	{
		popFront();
		return true;
	}
	else
	{
		trailer->setNext(spot->getNext());
		
		DLNode* newNext = spot->getNext();		// Rob
		if(newNext == 0) {						// Rob
			tail = trailer;
		} else {
			newNext->setPrevious(trailer);
		}

		delete spot;
		--mNodeCount;
		return true;
	}
}

bool DLList::removeAll(int target)
{
	if (removeFirst(target) == false)
		return false;
	while (removeFirst(target));
	return true;
}

void DLList::clear()
{
	while (mHead != NULL)
		popFront();
	mHead = NULL;
	mTail = NULL;
}

ostream& operator <<(ostream& out, const DLList& src)
{
	if (src.mHead == NULL)
	{
		out << "LIST EMPTY";
	}
	else
	{
		DLNode* spot = src.mHead;
		while (spot != NULL)
		{
			out << spot->getContents();
			if (spot->getNext() != NULL)
				out << ',';
			spot = spot->getNext();
		}
		if (spot == src.mHead)
			out << "LIST EMPTY";
	}
	return out;
}
