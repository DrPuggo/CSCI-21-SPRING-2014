#pragma once

#include "Item.h"

class MagicItem : public Item
{
        string mDescription;
        unsigned int mManaRequired;
    public:
        MagicItem(string name = "item", unsigned int value = 0, 
                  string description = "no description", 
                  unsigned int manaRequired = 0);
        virtual ~MagicItem();
        void setDescription(string description);
        void setManaRequired(unsigned int manaRequired);
        string getDescription();
        unsigned int getManaRequired();
        string toString();
    protected:
    private:
};
