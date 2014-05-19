#include "MagicItem.h"

MagicItem::MagicItem(string name, unsigned int value, 
                     string description, unsigned int manaRequired)
: Item(name, value), mDescription(description), mManaRequired(manaRequired)
{
}

MagicItem::~MagicItem()
{
}

void MagicItem::setDescription(string description)
{
    mDescription = description;
}

void MagicItem::setManaRequired(unsigned int manaRequired)
{
    mManaRequired = manaRequired;
}

string MagicItem::getDescription()
{
    return mDescription;
}

unsigned int MagicItem::getManaRequired()
{
    return mManaRequired;
}

string MagicItem::toString()
{
    stringstream ss;
    ss << Item::toString() << ", " << mDescription << ", " << "requires " 
       << mManaRequired << " mana";
    return ss.str();
}
