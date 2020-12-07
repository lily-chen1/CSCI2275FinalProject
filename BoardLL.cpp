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

/*
adds a new node to the end of the list
nothing needs to be passed as input because the 
tileNode constructor randomly generates the type
*/
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

/*
print out all tile nodes of the board linked list in order
starting from the head node
*/
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

/*
just calls the printInOrderBST() function from the pointsBST class
because it's inacessible from the driver file
*/
void BoardLL::printPointsBST()
{
    points.printInOrderBST();
}

/*
same logic as the function above, this time calling the findTotalPoints() function
from the points BST class
*/
void BoardLL::findTotalPoints()
{
    points.findTotalPoints();
}

/*
generates the board
it takes the number of tiles that's given as input
and just uses it in a for loop that calls addTile()
for the number of tiles given as input
*/
void BoardLL::buildBoard(int numberOfTiles)
{
    for (int i = 0; i < numberOfTiles; i++)
    {
        addTile();
    }
}

/*
generates a random number from 1 to 6 to simulate rolling a die
just like a traditional board game, the number that you roll is the
number of spaces that you move forward. as in it will get the current 
tile that the player is on and get that tile node's next for the 
number of that the player rolled. so for example rolling a 4 and moving 
4 spaces means you move 4 linked list nodes down. at the end it
gets the type of the link list node that you land on and it calls functions
from the pointsBST class based on it
*/
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
