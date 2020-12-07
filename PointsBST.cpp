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
    printBST(root);
    cout << endl;
    return;
}

int PointsBST::countBSTNodes()
{
    int count = 0;
    if (root != NULL)
    {
        count++;
        countBSTNodes(root, &count);
    }
    cout << endl
         << "you currently have " << count << " point orbs" << endl;
    return count;
}

void PointsBST::addPointNode(int value)
{

    int comparisonCount = 0;
    BSTNode *insNode = new BSTNode(value, NULL, NULL, NULL);
    // if tree is empty
    if (root == NULL)
    {
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

void PointsBST::printPreOrderBST(BSTNode *node)
{
}

void PointsBST::countBSTNodes(BSTNode *node, int *c)
{
    if (node->leftChild != NULL)
    {
        *c = *c + 1;
        countBSTNodes(node->leftChild, c);
    }
    if (node->rightChild != NULL)
    {
        *c = *c + 1;
        countBSTNodes(node->rightChild, c);
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
