#include <iostream>
#include <stdio.h>
using namespace std;


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

// has game ended
bool game_ended();

int main() 
{
    cout << "hello, and welcome to tic tac toe" << endl;
    cout << "This is how the spots are labeled:" << endl;
    cout << " 1 | 2 | 3 \n" << wall << " 4 | 5 | 6 \n" << wall << " 7 | 8 | 9 \n" << endl;

    // main game loop
    for (char i : turns)
    {
        char player = i;
        cout << "here is the current board:\n";
        print_board();
        cout << "it is player " << player << "'s turn!" << endl << "choose a space from 1 to 9:  ";
        int space;
        cin >> space;
        make_play(player, space);

        if (game_ended())
        {
            cout << "the game ended!\nHere is the final board:\n";
            print_board();
            break;
        }
    }

    return 0;
}

void make_play(char player, int space)
{
    space -= 1;
    int col = space % 3;
    int row = space / 3; // int division on purpose;

    // do not let them make an invalid play
    while (board[row][col] != ' ')
    {
        cout << "that is an invalid play, ";
        cout << "choose a space from 1 to 9:  ";
        int newspace;
        cin >> newspace;
        newspace -= 1;
        col = newspace % 3;
        row = newspace / 3;
    }
    
    board[row][col] = player;
    

}

void print_board()
{
    printf(" %c | %c | %c \n-----------\n %c | %c | %c \n-----------\n %c | %c | %c \n\n", 
        board[0][0], board[0][1], board[0][2], 
        board[1][0], board[1][1], board[1][2],
        board[2][0], board[2][1], board[2][2]);
}

bool game_ended()
{
    // handle a horizontal or a vertical 3 in a row
    for (int i = 0; i < 3; ++i)
    {
        
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            cout << board[0][i] << " wins vertically!" << endl;
            return true;
        }
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            cout << board[0][i] << " wins horizontally!" << endl;
            return true;
        }
    }
    // handle diagonal wins
    bool diag1 = false, diag2 = false;
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        diag1 = true;
    if (board[2][0] == board[1][1] && board[1][1] == board[0][2])
        diag2 = true;
    if (board[1][1] == ' ')
    {
        diag1 = false;
        diag2 = false;
    }
    if (diag1 || diag2)
    {
        cout << board[1][1] << " wins diagonally!" << endl;
        return true;
    }


    // handle ties
    bool tie = true;
    for (int i = 0; i < 3; ++i)
        for (int b = 0; b < 3; ++b)
            if (board[i][b] == ' ')
                tie = false;
    if (tie)
    {
        cout << "it is a tie!" << endl;
        return true;
    }
    return false;
    
    
}