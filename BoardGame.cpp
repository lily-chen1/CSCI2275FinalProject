/*
Lily Chen
CSCI 2275
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "BoardLL.h"

using namespace std;

int main(int argc, char *argv[])
{
    BoardLL boardGame;

    std::string dmenu = "======Main Menu=====\n"
                        "1. Start a new game\n"
                        "2. Roll the die\n"
                        "3. Print board\n"

                        "4. Quit";

    int choice;
    bool exit = false;

    cout << dmenu << endl;

    while (cin >> choice)
    {

        // flush the newlines and other characters
        cin.clear();
        cin.ignore();

        switch (choice)
        {
        case 1:
        {
            int numberOfTiles;
            cout << "Generating a new board..." << endl
                 << "What is the number of tiles you want the board to have?" << endl;
            cin >> numberOfTiles;
            boardGame.buildBoard(numberOfTiles);
            break;
        }

        case 2:
        {
            boardGame.rollTheDie();
            break;
        }
        case 3:
        {
            boardGame.printBoard();
            break;
        }
        case 4:
        {
            exit = true;
            break;
        }
        }

        if (exit)
        {
            break;
        }

        cout << dmenu << endl;
    }
}