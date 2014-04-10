#include "SLNode.h"

SLNode::SLNode()
: mContents(0), mNextNode(NULL)
{
}

SLNode::SLNode(int contents)
: mContents(contents), mNextNode(NULL)
{
}

SLNode::~SLNode()
{
    mNextNode = NULL;
}

void SLNode::setContents(int contents)
{
    mContents = contents;
}

void SLNode::setNextNode(SLNode* nextNode)
{
    mNextNode = nextNode;
}

int SLNode::getContents()
{
    return mContents;
}

SLNode* SLNode::getNextNode()
{
    return mNextNode;
}
