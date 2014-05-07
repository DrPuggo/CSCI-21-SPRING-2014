#pragma once

#include "BSTNode.h"

#include <iostream>
using std::cout;
using std::endl;

class BSTree
{
        BSTNode* mRoot;
        unsigned int mSize;
    public:
        BSTree();
        ~BSTree();
        bool insert(int data);
        void clear();
        unsigned int getSize() const;
        void inOrder();
    protected:
    private:
        bool insert(int data, BSTNode*& root);
        void clear(BSTNode*& root);
        void inOrder(BSTNode* root);
};
