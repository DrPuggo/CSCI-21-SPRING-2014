/*
 * Box.cpp
 * A simple class that stores the attributes of a box.
 * 
 * Written by			:	Jacob Slaton
 * Date Created			:	Feb 26, 2014
 * Last Date Modified	:	Apr 2, 2014
 *
 * <sources_go_here>
 */

#include "Box.h"
 
Box::Box(unsigned int boxNumber, string boxColor, unsigned int prizeCapacity)
: mBoxNumber(boxNumber), mBoxColor(boxColor), mPrizeCapacity(prizeCapacity), mPrizeCount(0)
{
    mPrizes = new Prize[mPrizeCapacity];
    for (unsigned int i = 0; i < mPrizeCapacity; ++i)
        mPrizes[i] = mScratch;
}

Box::~Box()
{
    delete [] mPrizes;
}

void Box::setBoxNumber(unsigned int boxNumber)
{
    mBoxNumber = boxNumber;
}

void Box::setBoxColor(string boxColor)
{
    mBoxColor = boxColor;
}

unsigned int Box::getBoxNumber()
{
    return mBoxNumber;
}

string Box::getBoxColor()
{
    return mBoxColor;
}

unsigned int Box::getPrizeCapacity()
{
    return mPrizeCapacity;
}

unsigned int Box::getPrizeCount()
{
    return mPrizeCount;
}

bool Box::addPrize(Prize prize)
{
    if (mPrizeCount >= mPrizeCapacity)
        return false;
    
    mPrizes[mPrizeCount++] = prize;
    return true;
}

Prize& Box::getPrize(unsigned int index)
{
    if (index < mPrizeCapacity)
        return mPrizes[index];
    return mScratch;
}

Prize Box::removePrize(unsigned int index)
{
    if (index >= mPrizeCount)
		return mScratch;
	
	Prize returnMe = mPrizes[index];
	mPrizes[index] = mScratch;
	--mPrizeCount;

	for (unsigned int i = index; i < mPrizeCount; ++i)
		mPrizes[i] = mPrizes[i + 1];

	return returnMe;
}
