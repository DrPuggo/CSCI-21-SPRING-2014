#include "BSTNode.h"

BSTNode::BSTNode(int contents)
: mContents(contents), mRightChild(NULL), mLeftChild(NULL)
{
}

BSTNode::~BSTNode()
{
    mRightChild = NULL;
    mLeftChild = NULL;
}

void BSTNode::setContents(int contents)
{
    mContents = contents;
}

void BSTNode::setRightChild(BSTNode* rightChild)
{
    mRightChild = rightChild;
}

void BSTNode::setLeftChild(BSTNode* leftChild)
{
    mLeftChild = leftChild;
}

int BSTNode::getContents() const
{
    return mContents;
}

int& BSTNode::getContents()
{
    return mContents;
}

BSTNode* BSTNode::getRightChild() const
{
    return mRightChild;
}

BSTNode*& BSTNode::getRightChild()
{
    return mRightChild;
}

BSTNode* BSTNode::getLeftChild() const
{
    return mLeftChild;
}

BSTNode*& BSTNode::getLeftChild()
{
    return mLeftChild;
}
