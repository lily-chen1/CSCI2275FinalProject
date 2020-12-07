#ifndef BOARDLL_H
#define BOARDLL_H

#include <iostream>
using namespace std;

struct tileNode
{
    string tileTypes[7] = {
        "add a point node of a random value",
        "add a point node of a random value",
        "add a point node of a random value",
        "add a point node of a random value",
        "discard the lowest value point node you have",
        "discard the highest value point node you have",
        "discard all point nodes you have that are in a random range of values"};
    string type;
    int value = 0;
    int value2 = 0;
    tileNode *next = NULL;
    tileNode *previous = NULL;
    tileNode()
    {
        int randomNumber = 0;
        randomNumber = rand() % 6 + 1;
        type = tileTypes[randomNumber];
        randomNumber = rand() % 100 + 1;
        value = randomNumber;
        value2 = rand() % 100 + 1;
    };
};
class BoardLL
{
public:
    BoardLL();
    void buildBoard(int numberOfTiles);
    void printBoard();
    void rollTheDie();
    void printPointsBST();
    void findTotalPoints();

protected:
private:
    tileNode *firstTile = NULL; //head of the linked list
    tileNode *lastTile = NULL;  //tail of the linked list
    tileNode *currentTile = NULL;
    void addTile();
    void addPassengers(std::string name, int numPassengers);
};

#endif
