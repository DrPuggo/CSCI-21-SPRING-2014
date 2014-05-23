//
// Grader comments 2015.05.22
// -30 points total
//
/*
 * BSTree.h
 * A simple, templated binary search tree.
 * 
 * Jacob Slaton
 * Date Created: May 16, 2014
 * Last Date Modified: May 16, 2014
 */

#pragma once
#include <iostream>	// Added by Rob for unit test
#include "BSTNode.h"
using std::cout;
using std::endl;

template<class T>
class BSTree
{
        BSTNode<T>* mRoot;
        unsigned int mSize;
    public:
    	
        //  Rob: added for testing
		BSTNode<T>* getNode(T const& inContents) {
			return getNode(inContents, getRoot());
		}
		
		// Rob: added for testing
		BSTNode<T>* getRoot() {
			return mRoot;
		}
    	
		// Rob added for testing
		BSTNode<T>* getNode(T const& inContents, BSTNode<T>* inBaseOfBranch) {
			if(inBaseOfBranch == 0) {
				return 0;
			} else {
				if(inContents == inBaseOfBranch->getData()) {
					return inBaseOfBranch;
				} else if(inContents < inBaseOfBranch->getData()) {
					return getNode(inContents, inBaseOfBranch->getLeftChild());
				} else {
					return getNode(inContents, inBaseOfBranch->getRightChild());
				}
			}
		}
        /*
         * Initiallizes the tree's root to NULL and size to 0.
         */
        BSTree()
        : mRoot(NULL), mSize(0)
        {
        }
        
        /*
         * Cleans up the tree by making a call to clear.
         */
        ~BSTree()
        {
            clear(mRoot);
        }
        
        /*
         * Returns the size of the tree.
         */
        unsigned int getSize() const
        {
            return mSize;
        }
        
        /*
         * Clears the tree.
         * Calls the private clear function.
         */
        void clear()
        {
            clear(mRoot);
        }
        
        /*
         * Inserts data into the tree.
         * Calls the private insert function.
         * @param data the data to be inserted.
         * @return true if data was inserted successfully, else false.
         */
        bool insert(T data)
        {
            return insert(data, mRoot);
        }
        
        /*
         * Searches the tree to check if it contains data.
         * Calls the private find function.
         * @param data the data to search for
         * @return true if found, else false
         */
        bool find(T data)
        {
            return find(data, mRoot);
        }
        
        /*
         * Removes data from the tree.
         * Calls the private remove function.
         * @param data the data to remove
         * @return true if removed, else false
         */
        bool remove(T data)
        {
            return remove(data, mRoot);
        }
        
        /*
         * Finds and returns target.
         * Calls the private remove function.
         * @param target the data to search for
         * @return a pointer to the target data, else NULL
         */
        T* get(T target)
        {
            return get(target, mRoot);
        }
        
        /*
         * Prints the contents of the tree in ascending order.
         * Calls the private inOrder function.
         */
        void inOrder()
        {
            inOrder(mRoot);
        }
        
        /*
         * Prints the contents of the tree in descending order.
         * Calls the private reverseOrder function.
         */
        void reverseOrder()
        {
            reverseOrder(mRoot);
        }
        
    protected:
    private:
        /*
         * Clears the tree.
         * @param root the private root of the tree
         */
        void clear(BSTNode<T>*& root)
        {
            if (root == NULL)
                return;
            clear(root->getLeftChild());
            clear(root->getRightChild());
            delete root;
            root = NULL;
            --mSize;
        }
        
        /*
         * Inserts data into the tree.
         * @param data the data to be inserted.
         * @param root the private root of the tree
         * @return true if data was inserted successfully, else false.
         */
        bool insert(T data, BSTNode<T>*& root)
        {
            if (root == NULL)
            {
                root = new BSTNode<T>(data);
                ++mSize;
                return true;
            }
            if (data < root->getData())
                return insert(data, root->getLeftChild());
            if (data > root->getData())
                return insert(data, root->getRightChild());
            return false;
        }
        
        /*
         * Searches the tree to check if it contains data.
         * @param data the data to search for
         * @param root the private root of the tree
         * @return true if found, else false
         */
        bool find(T target, BSTNode<T>*& root)
        {
            if (!root)
                return false;
            if (target < root->getData())
                return find(target, root->getLeftChild());
            if (target > root->getData())
                return find(target, root->getRightChild());
            return true;
        }
        
        /*
         * Removes data from the tree.
         * @param data the data to remove
         * @param root the private root of the tree
         * @return true if removed, else false
         */
        bool remove(T data, BSTNode<T>*& root)
        {
            if (!root)
                return false;
            if (data < root->getData())
                return remove(data, root->getLeftChild());
            if (data > root->getData())
                return remove(data, root->getRightChild());
            if (!root->getLeftChild())
            {
                BSTNode<T>* oldRoot = root;
                root = root->getRightChild();
                delete oldRoot;
                oldRoot = NULL;
                --mSize;
            }
            else
                removeMax(root->getData(), root->getLeftChild());
            return true;
        }
        
        /*
         * Finds and removes the largest value in the tree (or subtree).
         * @param removed the data that was removed
         * @param root the private root of the tree
         */
        void removeMax(T& removed, BSTNode<T>*& root)
        {
            if (!root->getRightChild())
            {
                BSTNode<T>* oldRoot = root;
                removed = root->getData();
                root = root->getLeftChild();
                delete oldRoot;
                oldRoot = NULL;
                --mSize;
            }
            else
                removeMax(removed, root->getRightChild());
        }
        
        /*
         * Finds and returns target.
         * @param target the data to search for
         * @param root the private root of the tree
         * @return a pointer to the target data, else NULL
         */
        T* get(T target, BSTNode<T>*& root)
        {
            if (!root)
                return NULL;
            if (target < root->getData())
                return get(target, root->getLeftChild());
            if (target > root->getData())
                return get(target, root->getRightChild());
            return &(root->getData());
        }
        
        /*
         * Prints the contents of the tree in ascending order.
         */
        void inOrder(BSTNode<T>* root)
        {
            if (root == NULL)
                return;
            inOrder(root->getLeftChild());
            cout << root->getData() << endl;
            inOrder(root->getRightChild());
        }
        
        /*
         * Prints the contents of the tree in descending order.
         */
		//
		// Grader comments 2014.05.22
		// This should call reverseOrder recursively, not inOrder()
		// -30 points
		//
        void reverseOrder(BSTNode<T>* root)
        {
            if (root == NULL)
                return;
            reverseOrder(root->getRightChild());
            cout << root->getData() << endl;
            reverseOrder(root->getLeftChild());
        }
};
