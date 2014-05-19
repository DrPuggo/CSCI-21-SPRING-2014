#pragma once

#include "Item.h"

class FoodItem : public Item
{
        unsigned int mCalories;
        string mUnitOfMeasure;
        float mUnits;
    public:
        FoodItem(string name = "item", unsigned int value = 0, 
                 unsigned int calories = 0, string unitOfMeasure = "nounits", 
                 float units = 0);
        virtual ~FoodItem();
        void setCalories(unsigned int calories);
        void setUnitOfMeasure(string unitOfMeasure);
        void setUnits(float units);
        unsigned int getCalories();
        string getUnitOfMeasure();
        float getUnits();
        string toString();
    protected:
    private:
};
