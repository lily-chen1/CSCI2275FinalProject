/*
Lily Chen
CSCI 2275
*/

#include "BoardLL.h"
#include "PointsBST.h"
#include <string>
#include <time.h>
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
    srand(time(NULL));
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
}
