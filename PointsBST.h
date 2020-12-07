#ifndef PointsBST_H
#define PointsBST_H

#include <string>

struct BSTNode
{
    int value;
    int count;
    BSTNode *parent;
    BSTNode *leftChild;
    BSTNode *rightChild;

    BSTNode(int in_value, BSTNode *p, BSTNode *lc, BSTNode *rc)
    {
        value = in_value;
        count = 1;
        parent = p;
        leftChild = lc;
        rightChild = rc;
    };
};

class PointsBST
{

public:
    PointsBST();
    void printValue(int value);
    void printInOrderBST();
    int countBSTNodes();
    void addPointNode(int value);
    void findValueRange(int value1, int value2);
    void deleteMinValue();
    void deleteMaxValue();
    bool isEmpty();

protected:
private:
    void printBST(BSTNode *node);
    void printPreOrderBST(BSTNode *node);
    void countBSTNodes(BSTNode *node, int *c);
    BSTNode *searchBST(int value); //use this function to find pointer to node in BST

    BSTNode *root = NULL;
};

#endif
