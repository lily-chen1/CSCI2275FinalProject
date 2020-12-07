#ifndef PointsBST_H
#define PointsBST_H

#include <string>

struct BSTNode
{
    int value;
    BSTNode *parent;
    BSTNode *leftChild;
    BSTNode *rightChild;

    BSTNode(int in_value, BSTNode *p, BSTNode *lc, BSTNode *rc)
    {
        value = in_value;
        parent = p;
        leftChild = lc;
        rightChild = rc;
    };
};

class PointsBST
{

public:
    PointsBST();
    void printInOrderBST();
    void findTotalPoints();
    void deleteTree();
    void addPointNode(int value);
    void deleteMinValue();
    void deleteMaxValue();
    bool isEmpty();
    BSTNode *leftMost(BSTNode *root);
    BSTNode *deleteNode(BSTNode *root);
    void removeRange(int low, int high);

protected:
private:
    void printBST(BSTNode *node);
    void findTotalPointsHelper(BSTNode *node, int *c);
    void deleteTreeHelper(BSTNode *node);
    BSTNode *removeRangeHelper(BSTNode *node, int low, int high);

    BSTNode *root = NULL;
};

#endif
