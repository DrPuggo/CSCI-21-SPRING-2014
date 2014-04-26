/*
 * DLNode.cpp
 * <description_here>
 *
 * Version				:	0.0.0
 * Author				:	Jacob Slaton
 * Date Created			:	Apr 19, 2014
 * Last Date Modified	:	Apr 19, 2014
 */

#pragma once

#include <cstdlib>

class DLNode
{
	int mContents;
	DLNode* mNext;
	DLNode* mPrev;
public:
    /*
     * Constructor for DLNode. Simply initializes the member variables.
	 * @param contents the contents to be stored in the node
     */
	DLNode(int contents = 0);
	
    /*
     * Effectively does nothing.
     */
	virtual ~DLNode();
	
    /*
     * Sets the value of contents.
     * @param contents sets the value stored in the node to contents
     */
	void setContents(int contents);
	
	/*
     * Sets the next node that this node points to.
     * @param next sets the next node this node points to
     */
	void setNext(DLNode* next);
	
	/*
     * Sets the previous node that this node points to.
     * @param prev sets the previous node this node points to
     */
	void setPrevious(DLNode* prev);
	
    /*
     * Returns the contents of the node.
     * @return mContents
     */
	int getContents() const;
	
    /*
     * Returns a pointer to the next node.
     * @return a pointer to the next node
     */
	DLNode* getNext() const;

    /*
     * Returns a pointer to the previous node.
     * @return a pointer to the previous node
     */
	DLNode* getPrevious() const;
protected:
private:
};
