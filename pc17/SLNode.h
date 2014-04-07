#pragma once

#include <cstdlib>

class SLNode
{
    int mContents;
    SLNode* mNextNode;
public:
    SLNode();
    SLNode(int contents);
    ~SLNode();
    void setContents(int contents);
    void setNextNode(SLNode* nextNode);
    int getContents();
    SLNode* getNextNode();
};
