#include "SList.h"

SList::SList()
: mHead(NULL), mNumNodes(0)
{
}

SList::~SList()
{
    clear();
}

void SList::insertHead(int value)
{
    SLNode* temp = new SLNode(value);
    temp->setNextNode(mHead);
    mHead = temp;
    ++mNumNodes;
}

void SList::removeHead()
{
    if (mHead == NULL)
        return;
        
    SLNode* temp = mHead;
    mHead = mHead->getNextNode();
    delete temp;
    temp = NULL;
    --mNumNodes;
}

void SList::clear()
{
    while (mHead != NULL)
        removeHead();
}

unsigned int SList::getSize()
{
    return mNumNodes;
}

string SList::toString()
{
    stringstream ss;
    for (SLNode* i = mHead; i != NULL; i = i->getNextNode())
    {
        ss << i->getContents();
        if (i->getNextNode() != NULL)
            ss << ',';
    }
    return ss.str();
}
