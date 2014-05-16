#include "BSTree.h"

BSTree::BSTree()
: mRoot(NULL), mSize(0)
{
}

BSTree::~BSTree()
{
    clear();
}

bool BSTree::insert(int data)
{
    return insert(data, mRoot);
}

bool BSTree::remove(int data)
{
    return remove(data, mRoot);
}

void BSTree::clear()
{
    clear(mRoot);
}

unsigned int BSTree::getSize() const
{
    return mSize;
}

void BSTree::inOrder()
{
    inOrder(mRoot);
}

bool BSTree::insert(int data, BSTNode*& root)
{
    if (root == NULL)
    {
        root = new BSTNode(data);
        ++mSize;
        return true;
    }
    if (data < root->getContents())
        return insert(data, root->getLeftChild());
    if (data > root->getContents())
        return insert(data, root->getRightChild());
    return false;
}

bool BSTree::remove(int data, BSTNode*& root)
{
    if (!root)
        return false;
    if (data < root->getContents())
        return remove(data, root->getLeftChild());
    if (data > root->getContents())
        return remove(data, root->getRightChild());
    if (!root->getLeftChild())
    {
        BSTNode* oldRoot = root;
        root = root->getRightChild();
        delete oldRoot;
        oldRoot = NULL;
        --mSize;
    }
    else
        removeMax(root->getContents(), root->getLeftChild());
    return true;
}

void BSTree::removeMax(int& removed, BSTNode*& root)
{
    if (!root->getRightChild())
    {
        BSTNode* oldRoot = root;
        removed = root->getContents();
        root = root->getLeftChild();
        delete oldRoot;
        oldRoot = NULL;
        --mSize;
    }
    else
        removeMax(removed, root->getRightChild());
}

void BSTree::clear(BSTNode*& root)
{
    if (root == NULL)
        return;
    clear(root->getLeftChild());
    clear(root->getRightChild());
    delete root;
    root = NULL;
    --mSize;
}

void BSTree::inOrder(BSTNode* root)
{
    if (root == NULL)
        return;
    inOrder(root->getLeftChild());
    cout << root->getContents() << ' ';
    inOrder(root->getRightChild());
}
