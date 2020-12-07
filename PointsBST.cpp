#include <iostream>
#include <string>
#include "PointsBST.h"
using namespace std;

PointsBST::PointsBST()
{
}

void PointsBST::printWord(std::string word)
{
    int opCount;
    BSTNode *temp = searchBST(word, opCount);
    cout << "Word: " << temp->word << endl
         << "Count: " << temp->count << endl
         << "Parent: " << temp->parent->word << endl
         << "Left Child: " << temp->leftChild->word << endl
         << "Right Child: " << temp->rightChild->word << endl;
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
         << "there are " << count << " nodes in the BST" << endl;
    return count;
}

int PointsBST::addWordNode(std::string word)
{

    int comparisonCount = 0;
    // calls searchBST to check if node is already in tree
    BSTNode *temp = searchBST(word, comparisonCount);
    // if the node is already in the tree, increase the count for it but don't add a new node to the tree
    if (temp != NULL && temp->word == word)
    {
        comparisonCount++;
        temp->count = temp->count + 1;
        //cout << "BST: after " << comparisonCount << " comparisons it was determined that " << word << " was already in the tree, its count has been increased to " << temp->count << endl;
        //cout << "BST:" << comparisonCount << endl;
        return comparisonCount;
    }
    // instantiate node to insert
    BSTNode *insNode = new BSTNode(word, NULL, NULL, NULL);
    // if tree is empty
    if (root == NULL)
    {
        root = insNode;
        //cout << "BST: added " << word << " after " << comparisonCount << " comparisons" << endl;
        //cout << "BST:" << comparisonCount << endl;
        return comparisonCount;
    }
    BSTNode *prober = root;
    BSTNode *lagger;
    while (prober != NULL)
    {
        comparisonCount++;
        lagger = prober;

        if (word < prober->word)
        {
            prober = prober->leftChild;
        }
        else
        {
            prober = prober->rightChild;
        }
    }
    if (word < lagger->word)
    {
        lagger->leftChild = insNode;
        insNode->parent = lagger;
    }
    else
    {
        lagger->rightChild = insNode;
        insNode->parent = lagger;
    }
    //cout << "BST: added " << word << " after " << comparisonCount << " comparisons" << endl;
    //cout << "BST:" << comparisonCount << endl;
    return comparisonCount;
}

void PointsBST::findAlphaRange(std::string word1, std::string word2)
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
            if (temp->word <= word2 &&
                temp->word >= word1)
            {
                cout << temp->word << " ";
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
                if (temp->word <= word2 && temp->word >= word1)
                {
                    cout << temp->word << " ";
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
        cout << node->word << " ";
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

BSTNode *PointsBST::searchBST(std::string word, int &opCounter)
{
    if (root == NULL)
    {
        return NULL;
    }
    BSTNode *finder = root;

    while (finder->word != word && finder != NULL)
    {
        opCounter++;
        if (word < finder->word)
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
        else if (word > finder->word)
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
