#include <iostream>
using namespace std;

// the players
const char X = 'X';
const char O = 'O';

// the game board
char board[3][3];


const string turns = "XOXOXOXOX"; // save the turns as a string so easy transition
const string wall = "-----------\n";


int main() 
{
    cout << "hello, and welcome to tic tac toe" << endl;
    cout << "This is how the spots are labeled:" << endl;
    cout << " 1 | 2 | 3 \n" << wall << " 4 | 5 | 6 \n" << wall << " 7 | 8 | 9 \n" << endl;

    // main game loop
    for (char i : turns)
    {
        char player = i;
        cout << "it is player " << player << "'s turn!" << endl << "choose a space from 1 to 9" << endl;
    }

    return 0;
}