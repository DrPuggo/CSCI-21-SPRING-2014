#pragma once

#include <cstdlib>

class SLNode
{
    int mContents;
    SLNode* mNextNode;
public:
    /*
     * Constructor for SLNode. Simply initializes the member variables.
     */
    SLNode();
    
    /*
     * Overloaded constructor for SLNode.
     * @param contents sets mContents to contents
     */
    SLNode(int contents);
    
    /*
     * Effectively does nothing. It does set mNextNode to NULL.
     */
    ~SLNode();
    
    /*
     * Sets the value of contents.
     * @param contents sets mContents to contents
     */
    void setContents(int contents);
    
    /*
     * Sets the value of nextNode.
     * @param nextNode sets mNextNode to nextNode
     */
    void setNextNode(SLNode* nextNode);
    
    /*
     * Returns mContents.
     * @return mContents
     */
    int getContents();
    
    /*
     * Returns mNextNode.
     * @return mNextNode
     */
    SLNode* getNextNode();
protected:
private:
};
