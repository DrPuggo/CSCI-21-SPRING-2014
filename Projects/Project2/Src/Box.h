/*
 * Box.h
 * A simple class that stores the attributes of a box.
 * 
 * Written by			:	Jacob Slaton
 * Date Created			:	Feb 26, 2014
 * Last Date Modified	:	Apr 4, 2014
 *
 * <sources_go_here>
 */

#pragma once

#include <iostream>
#include "Prize.h"
using namespace::std;

class Box
{
	unsigned int mBoxNumber;
	string mBoxColor;
	Prize mScratch;
	Prize* mPrizes;
	unsigned int mPrizeCapacity;
	unsigned int mPrizeCount;
public:
	/*
	 * This constructor initializes all data members in the prize object.
	 * @param boxNumber the desired number of the box
	 * @param boxColor the desired color of the box
	 * @param prizeCapacity the maximum number of prizes the box will hold
	 */
	Box(unsigned int boxNumber = 0, string boxColor = "NO COLOR", unsigned int prizeCapacity = 5);
	
	/*
	 * This destructor cleans up the mPrizes array.
	 */
	~Box();
	
	/*
	 * Sets or resets the member variable mBoxNumber.
	 * @param boxNumber the new desired number
	 */
	void setBoxNumber(unsigned int boxNumber);
	
	/*
	 * Sets or resets the member variable mBoxColor.
	 * @param boxColor the new desired color
	 */
	void setBoxColor(string boxColor);
	
	/*
	 * Returns the member variable mBoxNumber.
	 * @return mBoxNumber
	 */
	unsigned int getBoxNumber();
	
	/*
	 * Returns the member variable mBoxColor.
	 * @return mBoxColor
	 */
	string getBoxColor();
	
	/*
	 * Returns the member variable mPrizeCapacity.
	 * @return mPrizeCapacity
	 */
	unsigned int getPrizeCapacity();
	
	/*
	 * Returns the member variable mPrizeCount.
	 * @return mPrizeCount
	 */
	unsigned int getPrizeCount();
	
	/*
	 * Adds a prize to the box.
	 * @prize the prize to be added
	 * @return true if the prize was successfully added else false
	 */
	bool addPrize(Prize prize);
	
	/*
	 * Get a reference to a prize from the box.
	 * @param index the index of the prize to return
	 * @return a reference to the removed prize else returns a reference to mScratch
	 */
	Prize& getPrize(unsigned int index);
	
	/*
	 * Remove a prize from the box.
	 * @param index the index of the prize to remove
	 * @return a copy of the removed prize else returns mScratch
	 */
	Prize removePrize(unsigned int index);
protected:
private:
};
