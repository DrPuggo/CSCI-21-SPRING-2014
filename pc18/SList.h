#pragma once

#include <cstdlib>
#include <string>
#include <sstream>
#include "SLNode.h"
using std::string;
using std::stringstream;

class SList
{
        SLNode* mHead;
        unsigned int mNumNodes;
    public:
        SList();
        virtual ~SList();
        void insertHead(int value);
        void removeHead();
        void clear();
        unsigned int getSize();
        string toString();
    protected:
    private:
};
