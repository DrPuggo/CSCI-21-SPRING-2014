/*
 * BSTNode.h
 * A simple, templated binary search tree node.
 * 
 * Jacob Slaton
 * Date Created: May 16, 2014
 * Last Date Modified: May 16, 2014
 */

#pragma once

#include <cstdlib>

template<class T>
class BSTNode
{
        T mData;
        BSTNode* mLeftChild;
        BSTNode* mRightChild;
    public:
        /*
         * Initializes the data in the node and sets its children to NULL.
         * @param data the data to be stored in the node
         */
        BSTNode(T data)
        : mLeftChild(NULL), mRightChild(NULL)
        {
            setData(data);
        }
        
        /*
         * Sets the node's children to NULL.
         */
        virtual ~BSTNode()
        {
            mLeftChild = NULL;
            mRightChild = NULL;
        }
        
        /*
         * Sets the data stored in the node.
         * @param data the data to be stored in the node
         */
        void setData(T data)
        {
            mData = data;
        }
        
        /*
         * Sets the node's left child.
         * @param leftChild the node's new left child
         */
        void setLeftChild(BSTNode* leftChild)
        {
            mLeftChild = leftChild;
        }
        
        /*
         * Sets the node's right child.
         * @param rightChild the node's new right child
         */
        void setRightChild(BSTNode* rightChild)
        {
            mRightChild = rightChild;
        }
        
        /*
         * Gets the data stored in the node.
         * @return the data to stored in the node
         */
        T getData() const
        {
            return mData;
        }
        
        /*
         * Gets the data stored in the node.
         * @return the data to stored in the node
         */
        T& getData()
        {
            return mData;
        }
        
        /*
         * Gets the node's left child.
         * @return a pointer to the node's left child
         */
        BSTNode* getLeftChild() const
        {
            return mLeftChild;
        }
        
        /*
         * Gets the node's left child.
         * @return a pointer to the node's left child
         */
        BSTNode*& getLeftChild()
        {
            return mLeftChild;
        }
        
        /*
         * Gets the node's right child.
         * @return a pointer to the node's right child
         */
        BSTNode* getRightChild() const
        {
            return mRightChild;
        }
        
        /*
         * Gets the node's right child.
         * @return a pointer to the node's right child
         */
        BSTNode*& getRightChild()
        {
            return mRightChild;
        }
        
    protected:
    private:
};
