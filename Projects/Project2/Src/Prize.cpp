/*
 * Prize.cpp
 * A simple class that stores the attributes of a prize.
 * 
 * Written by           :   Jacob Slaton
 * Date Created         :   Mar 3, 2014
 * Last Date Modified   :   Apr 4, 2014
 *
 * <sources_go_here>
 */

#include "Prize.h"

Prize::Prize(string prizeName, unsigned int prizeValue)
: mPrizeName(prizeName), mPrizeValue(prizeValue)
{
}

Prize::~Prize()
{
}

void Prize::setPrizeName(string prizeName)
{
	mPrizeName = prizeName;
}

void Prize::setPrizeValue(unsigned int prizeValue)
{
	mPrizeValue = prizeValue;
}

string Prize::getPrizeName()
{
	return mPrizeName;
}

unsigned int Prize::getPrizeValue()
{
	return mPrizeValue;
}

bool operator ==(const Prize& LHS, const Prize& RHS)
{
	return ((LHS.mPrizeName == RHS.mPrizeName) &&
			(LHS.mPrizeValue == RHS.mPrizeValue));
}
