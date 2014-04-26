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

void DLList::pushFront(int contents)
{
    DLNode* temp = new DLNode(contents);
    temp->setNext(mHead);
	if (mTail == NULL)
		mTail = temp;
    mHead = temp;
    ++mNodeCount;
}

void DLList::pushBack(int contents)
{
    DLNode* temp = new DLNode(contents);
    temp->setPrevious(mHead);
	if (mHead == NULL)
		mHead = temp;
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

bool DLList::get(int target)
{
	if (mHead == NULL)
		return false;
	DLNode* temp = mHead;
	while ((temp != NULL) && (temp->getNext()))
	{
		if (temp->getContents() == target)
			return true;
		temp = temp->getNext();
	}
	return false;
}

void DLList::popFront()
{
	if (mHead == NULL)
		return;
	DLNode* temp = mHead;
	if (mTail == mHead)
		mTail = NULL;
	mHead = mHead->getNext();
	mHead->setPrevious(NULL);
	delete temp;
}

void DLList::popBack()
{
	if (mTail == NULL)
		return;
	DLNode* temp = mTail;
	if (mHead == mTail)
		mHead = NULL;
	mTail = mTail->getPrevious();
	mTail->setNext(NULL);
	delete temp;
}

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
