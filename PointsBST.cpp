#include <iostream>
#include <string>
#include "PointsBST.h"
using namespace std;

PointsBST::PointsBST()
{
}

void PointsBST::printValue(int value)
{
    int opCount;
    BSTNode *temp = searchBST(value);
    cout << "Word: " << temp->value << endl
         << "Count: " << temp->count << endl
         << "Parent: " << temp->parent->value << endl
         << "Left Child: " << temp->leftChild->value << endl
         << "Right Child: " << temp->rightChild->value << endl;
}

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

void PointsBST::findValueRange(int value1, int value2)
{
    if (!root)
    {
        return;
    }
    BSTNode *temp = root;
    while (temp)
    {
        if (temp->leftChild == NULL)
        {
            // check if temp lies between word1 and word2
            if (temp->value <= value2 &&
                temp->value >= value1)
            {
                cout << temp->value << " ";
            }
            temp = temp->rightChild;
        }

        else
        {
            BSTNode *pre = temp->leftChild;
            while (pre->rightChild != NULL && pre->rightChild != temp)
            {
                pre = pre->rightChild;
            }

            if (pre->rightChild == NULL)
            {
                pre->rightChild = temp;
                temp = temp->leftChild;
            }
            else
            {
                pre->rightChild = NULL;
                // check if temp lies between word1 and word2
                if (temp->value <= value2 && temp->value >= value1)
                {
                    cout << temp->value << " ";
                }
                temp = temp->rightChild;
            }
        }
    }
    cout << endl;
}

void PointsBST::printBST(BSTNode *node)
{
    if (node != NULL)
    {
        printBST(node->leftChild);
        cout << node->value << " ";
        printBST(node->rightChild);
    }
}

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

BSTNode *PointsBST::searchBST(int value)
{
    if (root == NULL)
    {
        return NULL;
    }
    BSTNode *finder = root;

    while (finder->value != value && finder != NULL)
    {
        if (value < finder->value)
        {
            if (finder->leftChild != NULL)
            {
                finder = finder->leftChild;
            }
            else
            {
                return NULL;
            }
        }
        else if (value > finder->value)
        {
            if (finder->rightChild != NULL)
            {
                finder = finder->rightChild;
            }
            else
            {
                return NULL;
            }
        }
    }
    return finder;
}

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