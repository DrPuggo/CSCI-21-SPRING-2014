#pragma once

#include <iomanip>
#include <string>
#include <sstream>
using std::setprecision;
using std::string;
using std::stringstream;

class Item
{
        string mName;
        unsigned int mValue;
    public:
        Item(string name = "item", unsigned int value = 0);
        virtual ~Item();
        void setName(string name);
        void setValue(unsigned int value);
        string getName();
        unsigned int getValue();
        string toString();
    protected:
    private:
};
