#pragma once

#include <cstdlib>
#include <string>
#include <sstream>
#include "SLNode.h"
using std::string;
using std::stringstream;

template <class T>
class SList
{
    SLNode<T>* mHead;
    unsigned int mNumNodes;
public:
    /*
     * Constructor for SList. Simply initializes the member variables.
     */
    SList()
    : mHead(NULL), mNumNodes(0)
    {
    }
    
    /*
     * Deletes the list.
     */
    virtual ~SList()
    {
        clear();
    }

    /*
     * Inserts a new node in the list at the head.
     * @param value the data to be stored in the list.
     */
    void insertHead(T value)
    {
        SLNode<T>* temp = new SLNode<T>(value);
        temp->setNextNode(mHead);
        mHead = temp;
        ++mNumNodes;
    }

    /*
     * Inserts a new node in the list at the tail.
     * @param value the data to be stored in the list.
     */
    void insertTail(T value)
    {
        if (mHead == NULL)
        {
            insertHead(value);
            return;
        }
        
        SLNode<T>* temp = new SLNode<T>(value);
        
        SLNode<T>* i = mHead;
        while (i->getNextNode() != NULL)
            i = i->getNextNode();
        
        i->setNextNode(temp);
        
        ++mNumNodes;
    }

    /*
     * Remove the node at the head (if it exists).
     */
    void removeHead()
    {
        if (mHead == NULL)
            return;
            
        SLNode<T>* temp = mHead;
        mHead = mHead->getNextNode();
        delete temp;
        temp = NULL;
        --mNumNodes;
    }

    /*
     * Remove the node at the tail (if it exists).
     */
    void removeTail()
    {
        if (mHead == NULL)
            return;
        
        SLNode<T>* i = mHead;
        SLNode<T>* j = NULL;
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
    
    void insert(T value)
    {
        if (mHead == NULL)
        {
            insertHead(value);
        }
        else if (mHead->getNextNode() == NULL)
        {
            if (value < mHead->getContents())
                insertHead(value);
            else
                insertTail(value);
        }
        else
        {
            SLNode<T>* spot = mHead;
            SLNode<T>* trailer = NULL;
            while ((spot->getNextNode() != NULL) && (value > spot->getContents()))
            {
                trailer = spot;
                spot = spot->getNextNode();
            }
            if ((spot->getNextNode() == NULL) && (value > spot->getContents()))
            {
                insertTail(value);
            }
            else if (spot == mHead) // Note: (trailer == NULL) and (spot == mHead) are the same
            {
                insertHead(value);
            }
            else
            {
                SLNode<T>* temp = new SLNode<T>(value);
                temp->setNextNode(spot);
                trailer->setNextNode(temp);
                ++mNumNodes;
            }
        }
    }
    
    bool removeFirst(T target)
    {
        if (mHead == NULL)
            return false;
        
        SLNode<T>* spot = mHead;
        SLNode<T>* trailer = NULL;
        while ((spot != NULL) && (spot->getContents() != target))
        {
            trailer = spot;
            spot = spot->getNextNode();
        }
        
        if (spot == NULL)
        {
            return false;
        }
        else if (spot == mHead)
        {
            removeHead();
            return true;
        }
        else
        {
            trailer->setNextNode(spot->getNextNode());
            delete spot;
            --mNumNodes;
            return true;
        }
    }
    
    bool removeAll(T target)
    {
        if (removeFirst(target) == false)
            return false;
        while (removeFirst(target));
        return true;
    }
    
    /*
     * Deletes the contents of the list and sets mHead to NULL;
     */
    void clear()
    {
        while (mHead != NULL)
            removeHead();
    }

    /*
     * Returns the number of nodes in the list.
     * @return mNumNodes
     */
    unsigned int getSize()
    {
        return mNumNodes;
    }

    /*
     * Returns the contents of the list in the format "NUM1,NUM2,...,LASTNUM".
     * @return the list contents, or "" if mHead is NULL
     */
    string toString()
    {
        stringstream ss;
        for (SLNode<T>* i = mHead; i != NULL; i = i->getNextNode())
        {
            ss << i->getContents();
            if (i->getNextNode() != NULL)
                ss << ',';
        }
        return ss.str();
    }
protected:
private:
};
