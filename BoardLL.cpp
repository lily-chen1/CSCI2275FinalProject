/*
Lily Chen
CSCI 2275
*/

#include "BoardLL.h"
#include "PointsBST.h"
#include <string>
using namespace std;

PointsBST points;
BoardLL::BoardLL() {}

void BoardLL::addTile()
{
    tileNode *newTile = new tileNode();
    tileNode *last = firstTile;
    if (firstTile == NULL)
    {
        newTile->previous = NULL;
        firstTile = newTile;
        return;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = newTile;
    newTile->previous = last;
}

void BoardLL::printBoard()
{
    cout << "\nPrinting board..." << endl;
    tileNode *n = firstTile;
    while (n != NULL)
    {
        cout << n->type << " --> ";
        n = n->next;
    }
}

void BoardLL::printPointsBST()
{
    points.printInOrderBST();
}
void BoardLL::findTotalPoints()
{
    points.findTotalPoints();
}

void BoardLL::buildBoard(int numberOfTiles)
{
    for (int i = 0; i < numberOfTiles; i++)
    {
        addTile();
    }
}

void BoardLL::rollTheDie()
{
    if (currentTile == NULL)
    {
        currentTile = firstTile;
    }
    int randomNumber;
    randomNumber = rand() % 6 + 1;
    cout << "You rolled a " << randomNumber << endl;
    for (int i = 0; i < randomNumber; i++)
    {
        if (currentTile->next == NULL)
        {
            cout << "you have reached the end of the board" << endl;
            return;
        }
        currentTile = currentTile->next;
    }
    cout << "You landed on a tile bearing the inscription: " << currentTile->type << endl;
    if (currentTile->type == "discard the lowest value point node you have")
    {
        points.deleteMinValue();
    }
    else if (currentTile->type == "discard the highest value point node you have")
    {
        points.deleteMaxValue();
    }
    else if (currentTile->type == "add a point node of a random value")
    {
        randomNumber = rand() % 100 + 1;
        points.addPointNode(randomNumber);
    }
    else if (currentTile->type == "discard all point nodes you have that are in a random range of values")
    {
        int randomNumber2;
        randomNumber = rand() % 100 + 1;
        randomNumber2 = rand() % 100 + 1;
        if (randomNumber > randomNumber2)
        {
            int temp = randomNumber;
            randomNumber = randomNumber2;
            randomNumber2 = temp;
        }
        points.removeRange(randomNumber, randomNumber2);
    }
}
