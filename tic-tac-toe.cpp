#include <iostream>
#include <stdio.h>
using namespace std;

// the players
const char X = 'X';
const char O = 'O';

// the game board
char board[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};


const string turns = "XOXOXOXOX"; // save the turns as a string so easy transition
const string wall = "-----------\n";

// function to print the board;
void print_board();

// function to make a play
void make_play(char, int);

int main() 
{
    cout << "hello, and welcome to tic tac toe" << endl;
    cout << "This is how the spots are labeled:" << endl;
    cout << " 1 | 2 | 3 \n" << wall << " 4 | 5 | 6 \n" << wall << " 7 | 8 | 9 \n" << endl;
    print_board();

    // main game loop
    // for (char i : turns)
    // {
    //     char player = i;
    //     cout << "here is the current board:\n";
    //     print_board();
    //     cout << "it is player " << player << "'s turn!" << endl << "choose a space from 1 to 9:  ";
    //     int space;
    //     cin >> space;
    //     make_play(player, space);
    // }

    return 0;
}

void make_play(char player, int space)
{
    space -= 1;
    int col = space % 3;
    int row = space / 3; // int division on purpose;

    // recursively make plays if invalid play
    if (board[row][col] != ' ')
    {
        cout << "that is an invalid play, ";
        cout << "choose a space from 1 to 9:  ";
        int newspace;
        cin >> newspace;
        make_play(player, newspace);
    }
    else
    {
        board[row][col] = player;
    }

}

void print_board()
{
    printf(" %c | %c | %c \n-----------\n %c | %c | %c \n-----------\n %c | %c | %c \n", 
        board[0][0], board[0][1], board[0][2], 
        board[1][0], board[1][1], board[1][2],
        board[2][2], board[2][1], board[2][2]);
}