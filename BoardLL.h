#ifndef BOARDLL_H
#define BOARDLL_H

#include <iostream>
#include <time.h>
using namespace std;

struct tileNode
{
    string tileTypes[4] = {
        "discard the lowest value point node you have",
        "discard the highest value point node you have",
        "add a point node of a random value",
        "discard all point nodes you have that are in a random range of values"};
    string type;
    int value = 0;
    int value2 = 0;
    tileNode *next = NULL;
    tileNode *previous = NULL;
    tileNode()
    {
        int randomNumber = 0;
        //srand(time(NULL));
        randomNumber = rand() % 3 + 1;
        type = tileTypes[randomNumber];
        //srand(time(NULL));
        randomNumber = rand() % 100 + 1;
        value = randomNumber;
        //srand(time(NULL));
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

protected:
private:
    tileNode *firstTile = NULL; //head of the linked list
    tileNode *lastTile = NULL;  //tail of the linked list
    tileNode *currentTile = NULL;
    void addTile();
    void addPassengers(std::string name, int numPassengers);
};

#endif
