#pragma once

#include <cstdlib>

template <class T>
class SLNode
{
    T mContents;
    SLNode* mNextNode;
public:
    /*
     * Constructor for SLNode. Simply initializes the member variables.
     */
    SLNode()
    : mNextNode(NULL)
    {
    }
    
    /*
     * Overloaded constructor for SLNode.
     * @param contents sets mContents to contents
     */
    SLNode(T contents)
    : mContents(contents), mNextNode(NULL)
    {
    }
    
    /*
     * Effectively does nothing. It does set mNextNode to NULL.
     */
    ~SLNode()
    {
        mNextNode = NULL;
    }
    
    /*
     * Sets the value of contents.
     * @param contents sets mContents to contents
     */
    void setContents(T contents)
    {
        mContents = contents;
    }

    /*
     * Sets the value of nextNode.
     * @param nextNode sets mNextNode to nextNode
     */
    void setNextNode(SLNode* nextNode)
    {
        mNextNode = nextNode;
    }
    
    /*
     * Returns mContents.
     * @return mContents
     */
    T getContents()
    {
        return mContents;
    }

    /*
     * Returns mNextNode.
     * @return mNextNode
     */
    SLNode* getNextNode()
    {
        return mNextNode;
    }
};
