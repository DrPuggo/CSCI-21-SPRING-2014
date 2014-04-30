/*
 * DLNode.cpp
 * <description_here>
 *
 * Version				:	0.0.0
 * Author				:	Jacob Slaton
 * Date Created			:	Apr 19, 2014
 * Last Date Modified	:	Apr 19, 2014
 */

#include "DLNode.h"

DLNode::DLNode(int contents)
: mContents(contents), mNext(NULL), mPrev(NULL)
{
}

DLNode::~DLNode()
{
}

void DLNode::setContents(int contents)
{
	mContents = contents;
}

void DLNode::setNext(DLNode* next)
{
	mNext = next;
}

void DLNode::setPrevious(DLNode* prev)
{
	mPrev = prev;
}

int DLNode::getContents() const
{
	return mContents;
}

DLNode* DLNode::getNext() const
{
	return mNext;
}

DLNode* DLNode::getPrevious() const
{
	return mPrev;
}
