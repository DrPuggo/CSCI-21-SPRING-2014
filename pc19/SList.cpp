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

void SList::insertTail(int value)
{
    if (mHead == NULL)
    {
        insertHead(value);
        return;
    }
    
    SLNode* temp = new SLNode(value);
    
    SLNode* i = mHead;
    while (i->getNextNode() != NULL)
        i = i->getNextNode();
    
    i->setNextNode(temp);
    
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

void SList::removeTail()
{
    if (mHead == NULL)
        return;
    
    SLNode* i = mHead;
    SLNode* j = NULL;
    while (i->getNextNode() != NULL)
    {
        j = i;
        i = i->getNextNode();
    }
    
    delete i;
    i = NULL;
    --mNumNodes;
    
    if (j == NULL)
        mHead = NULL;
    else
        j->setNextNode(NULL);
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
