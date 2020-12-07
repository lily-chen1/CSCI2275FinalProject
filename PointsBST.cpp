#include <iostream>
#include <string>
#include "PointsBST.h"
using namespace std;

PointsBST::PointsBST()
{
}

/*
uses recursion to print the BST in order from node with the least value
to the node with the greatest
*/
void PointsBST::printInOrderBST()
{
    if (root == NULL)
    {
        cout << "your points BST is currently empty" << endl;
        return;
    }

    printBST(root);
    cout << endl;
    return;
}

/*
private method called by printInOrderBST() for recursion
*/
void PointsBST::printBST(BSTNode *node)
{
    if (node != NULL)
    {
        printBST(node->leftChild);
        cout << node->value << " ";
        printBST(node->rightChild);
    }
}

/*
uses the same recursion from printInOrderBST() to sum up the values of the
nodes in the BST and find the total points that the player currently has
*/
void PointsBST::findTotalPoints()
{
    int count = 0;
    if (root != NULL)
    {
        findTotalPointsHelper(root, &count);
    }
    cout << endl
         << "you currently have a total of " << count << " points" << endl;
}

/*
private method called by findTotalPoints() for recursion
*/
void PointsBST::findTotalPointsHelper(BSTNode *node, int *c)
{
    *c = *c + node->value;
    if (node->leftChild != NULL)
    {
        findTotalPointsHelper(node->leftChild, c);
    }
    if (node->rightChild != NULL)
    {
        findTotalPointsHelper(node->rightChild, c);
    }
}

/*
adds a new point node to the points BST
*/
void PointsBST::addPointNode(int value)
{
    int comparisonCount = 0;
    BSTNode *insNode = new BSTNode(value, NULL, NULL, NULL);
    // if tree is empty
    if (root == NULL)
    {
        cout << "node with a value of " << value << " was added to the BST" << endl;
        root = insNode;
        return;
    }
    BSTNode *prober = root;
    BSTNode *lagger;
    while (prober != NULL)
    {
        lagger = prober;

        if (value < prober->value)
        {
            prober = prober->leftChild;
        }
        else
        {
            prober = prober->rightChild;
        }
    }
    if (value < lagger->value)
    {
        lagger->leftChild = insNode;
        insNode->parent = lagger;
    }
    else
    {
        lagger->rightChild = insNode;
        insNode->parent = lagger;
    }
    cout << "node with a value of " << value << " was added to the BST" << endl;
}

/*
finds the minimum value by going through the left childs until it hits the
minimum value
*/
void PointsBST::deleteMinValue()
{
    struct BSTNode *current = root;
    if (isEmpty())
    {
        cout << "your points BST is empty, so no nodes were discarded" << endl;
        return;
    }
    while (current->leftChild != NULL)
    {
        current = current->leftChild;
    }
    cout << "the minimum value node in the points BST with a value of " << current->value << " was discarded" << endl;
    if (current->rightChild != NULL && current->parent != NULL)
    {
        current->rightChild->parent = current->parent;
        current->parent->leftChild = current->rightChild;
    }
    else if (current->parent != NULL)
    {
        current->parent->leftChild = NULL;
    }
    else if (current = root)
    {
        if (current->rightChild != NULL)
        {
            current->rightChild->parent = NULL;
            root = current->rightChild;
        }
        else
        {
            //BST is now empty
            root = NULL;
        }
    }
    delete current;
}

void PointsBST::deleteMaxValue()
{
    struct BSTNode *current = root;
    if (isEmpty())
    {
        cout << "your points BST is empty, so no nodes were discarded" << endl;
        return;
    }
    while (current->rightChild != NULL)
    {
        current = current->rightChild;
    }
    cout << "the maximum value node in the points BST with a value of " << current->value << " was discarded" << endl;
    if (current->leftChild != NULL && current->parent != NULL)
    {
        current->leftChild->parent = current->parent;
        current->parent->rightChild = current->leftChild;
    }
    else if (current->parent != NULL)
    {
        current->parent->rightChild = NULL;
    }
    else if (current = root)
    {
        if (current->leftChild != NULL)
        {
            current->leftChild->parent = NULL;
            root = current->leftChild;
        }
        else
        {
            //BST is now empty
            root = NULL;
        }
    }
    delete current;
}

bool PointsBST::isEmpty()
{
    if (root == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// A Utility function to find leftMost node
BSTNode *PointsBST::leftMost(BSTNode *root)
{
    if (!root)
        return NULL;
    while (root->leftChild)
        root = root->leftChild;
    return root;
}

/* 
a recursive utility function to delete the give node used by removeRange()
note that I did not call this function in deleteMinValue() and
deleteMaxValue() because I though it would be overkill
and I want to be at least somewhat performant.
*/
BSTNode *PointsBST::deleteNode(BSTNode *node)
{
    if (node == root && node->leftChild == NULL && node->rightChild == NULL)
    {
        root = NULL;
        return NULL;
    }

    // node with only one chile or no child
    if (!node->leftChild)
    {
        BSTNode *child = node->rightChild;
        node = NULL;
        return child;
    }
    else if (!node->rightChild)
    {
        BSTNode *child = node->leftChild;
        node = NULL;
        return child;
    }

    // node with two children: get inorder successor
    // in the right subtree
    BSTNode *next = leftMost(node->rightChild);

    // copy the inorder successor's content to this node
    node->value = next->value;

    // delete the inorder successor
    node->rightChild = deleteNode(node->rightChild);

    return node;
}

// function to find node in given range and delete
// it in preorder manner
void PointsBST::removeRange(int low, int high)
{
    if (root == NULL)
    {
        cout << "your points BST is empty, so no nodes were discarded" << endl;
        return;
    }
    cout << "the random range is " << low << " to " << high << endl;
    removeRangeHelper(root, low, high);
}

BSTNode *PointsBST::removeRangeHelper(BSTNode *node, int low, int high)
{
    if (!node)
        return NULL;

    // First fix the left and right subtrees of node
    node->leftChild = removeRangeHelper(node->leftChild, low, high);
    node->rightChild = removeRangeHelper(node->rightChild, low, high);

    // Now fix the node.
    // if given node is in Range then delete it
    if (node->value >= low && node->value <= high)
    {
        cout << "the node with the value " << node->value << " fell within the range and was discarded" << endl;
        return deleteNode(node);
    }

    // Root is out of range
    return node;
}