/*
 * Prize.h
 * A simple class that stores the attributes of a prize.
 * 
 * Written by           :   Jacob Slaton
 * Date Created         :   Mar 3, 2014
 * Last Date Modified   :   Apr 4, 2014
 *
 * <sources_go_here>
 */

#pragma once

#include <string>
using std::string;

class Prize
{
	string mPrizeName;
	unsigned int mPrizeValue;
public:
	
	/*
	 * This constructor initializes all data members in the prize object.
	 * @param prizeName the desired name of the prize
	 * @param prizeValue the desired value of the prize
	 */
	Prize(string prizeName = "NO NAME", unsigned int prizeValue = 0);
	
	/*
	 * This destructor does nothing and is here for completeness.
	 */
	~Prize();
	
	/*
	 * Sets or resets the member variable mPrizeName.
	 * @param prizeName the new desired name
	 */
	void setPrizeName(string prizeName);
	
	/*
	 * Sets or resets the member variable mPrizeValue.
	 * @param prizeName the new desired value
	 */
	void setPrizeValue(unsigned int prizeValue);
	
	/*
	 * Returns the member variable mPrizeName.
	 * @return mPrizeName
	 */
	string getPrizeName();
	
	/*
	 * Returns the member variable mPrizeValue.
	 * @return mPrizeValue
	 */
	unsigned int getPrizeValue();
	
	/*
	 * This function overloads the == operator to compare two
	 * prizes to see if their names and values are the same.
	 * @param LHS the left hand side prize
	 * @param RHS the right hand side prize
	 * @return true if the prizes names and values are the same else false
	 */
	friend bool operator ==(const Prize& LHS, const Prize& RHS);
protected:
private:
};
