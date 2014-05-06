#include <cstdlib>

class BSTNode
{
        int mContents;
        BSTNode* mRightChild;
        BSTNode* mLeftChild;
    public:
        BSTNode(int contents = 0);
        virtual ~BSTNode();
        void setContents(int contents);
        void setRightChild(BSTNode* rightChild);
        void setLeftChild(BSTNode* leftChild);
        int getContents() const;
        int& getContents();
        BSTNode* getRightChild() const;
        BSTNode*& getRightChild();
        BSTNode* getLeftChild() const;
        BSTNode*& getLeftChild();
    protected:
    private:
};
