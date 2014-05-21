#include "TreasureChest.h"

void TreasureChest::addItem (const Item& newItem)
{
    chest.push_back(newItem);
}

void TreasureChest::insertItem (const Item& newItem, unsigned int position)
{
    chest.insert((chest.begin() + position), newItem);
}

const Item* TreasureChest::getItem (unsigned int position)
{
    if (position >= chest.size())
        return NULL;
    return &chest[position];
}

Item TreasureChest::removeItem (unsigned int position) throw (string)
{
    if (position >= chest.size())
        throw string("ERROR: attempting remove at invalid position");
    Item item = chest[position];
    chest.erase((chest.begin() + position));
    return item;
}

void TreasureChest::clear ()
{
    chest.clear();
}

bool TreasureChest::empty () const
{
    return chest.empty();
}

unsigned int TreasureChest::getSize () const
{
    return chest.size();
}

void TreasureChest::sortByName ()
{
    sort(chest.begin(), chest.end(), compareItemsByName);
}

void TreasureChest::sortByValue ()
{
    sort(chest.begin(), chest.end(), compareItemsByValue);
}

void TreasureChest::sortByQuantity ()
{
    sort(chest.begin(), chest.end(), compareItemsByQuantity);
}

ostream& operator<< (ostream& outs, const TreasureChest& src)
{
    for (unsigned int i = 0; i < src.getSize(); ++i)
    {
        outs << src.chest[i].name;
        if ((i + 1) < src.getSize())
            outs << ',';
    }
    return outs;
}

bool compareItemsByName (const Item& lsrc, const Item& rsrc)
{
    return (lsrc.name < rsrc.name);
}

bool compareItemsByValue (const Item& lsrc, const Item& rsrc)
{
    return (lsrc.value < rsrc.value);
}

bool compareItemsByQuantity (const Item& lsrc, const Item& rsrc)
{
    return (lsrc.quantity < rsrc.quantity);
}
