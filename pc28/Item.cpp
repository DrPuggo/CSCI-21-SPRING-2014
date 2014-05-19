#include "Item.h"

Item::Item(string name, unsigned int value)
: mName(name), mValue(value)
{
}

Item::~Item()
{
}

void Item::setName(string name)
{
    mName = name;
}

void Item::setValue(unsigned int value)
{
    mValue = value;
}

string Item::getName()
{
    return mName;
}

unsigned int Item::getValue()
{
    return mValue;
}

string Item::toString()
{
    stringstream ss;
    ss << mName << ", $" << mValue;
    return ss.str();
}
