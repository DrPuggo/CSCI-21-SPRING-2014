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
