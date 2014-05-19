//
// Grader comments 2014.05.19
// Fails two unit tests and produces extraneous output.
// -45 points
//
#include "FoodItem.h"

FoodItem::FoodItem(string name, unsigned int value, 
                   unsigned int calories, string unitOfMeasure, float units)
: Item(name, value), mCalories(calories),
  mUnitOfMeasure(unitOfMeasure), mUnits(units)
{
}

FoodItem::~FoodItem()
{
}

void FoodItem::setCalories(unsigned int calories)
{
    mCalories = calories;
}

void FoodItem::setUnitOfMeasure(string unitOfMeasure)
{
    mUnitOfMeasure = unitOfMeasure;
}

void FoodItem::setUnits(float units)
{
    mUnits = units;
}

unsigned int FoodItem::getCalories()
{
    return mCalories;
}

string FoodItem::getUnitOfMeasure()
{
    return mUnitOfMeasure;
}

float FoodItem::getUnits()
{
    return mUnits;
}

string FoodItem::toString()
{
    stringstream ss;
    ss << Item::toString() << ", " << mUnits << ' ' 
       << mUnitOfMeasure << ", " << mCalories << " calories";
    return ss.str();
}
