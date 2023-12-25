#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

void draw_board(char (&board)[3][3])
{
    cout << "     |     |     " << endl;
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "   " << board[2][0] << " |  " << board[2][1] << "  |  " << board[2][2] << endl;

    cout << "     |     |     " << endl
         << endl;
}

void get_position(int &x, int &y)
{
    bool bool1 = false;
    int a = x;
    int b = y;
    while (!bool1)
    {
        cout << "Enter the position of x and y" << endl;
        cout << "x: ";
        cin >> a;
        cout << "y: ";
        cin >> b;
        if (a > 2 || b > 2 || a < 0 || b < 0)
        {
            cout << "Invalid position! try again" << endl;
        }
        else
        {
            bool1 = true;
            x = a;
            y = b;
        }
    }
}

bool Iswinner(char (&board)[3][3])
{
    for (int row = 0; row < 3; row++)
    {
        if (board[row][0] == board[row][1] && board[row][1] == board[row][2] && board[row][0] != '_')
        {
            return true;
        }
    }
    for (int col = 0; col < 3; col++)
    {
        if (board[0][col] == board[1][col] && board[1][col] == board[2][col] && board[0][col] != '_')
        {
            return true;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != '_')
    {
        return true;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != '_')
    {
        return true;
    }
    return false;
}
void switch_player(char &player)
{
    if (player == 'X')
    {
        player = 'O';
    }
    else
    {
        player = 'X';
    }
}

void make_move(char (&board)[3][3], int &x, int &y, char player)
{
    board[x][y] = player;
}

bool Isfull(char (&board)[3][3])
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (board[row][col] == '_')
            {
                return false;
            }
        }

        return true;
    }
}

void play_game(char (&board)[3][3])
{
    char player = 'X';
    bool game_over = false;
    while (!game_over)
    {
        system("cls");
        cout << "Player " << player << "'s turn" << endl;
        draw_board(board);
        int x, y;
        get_position(x, y);
        make_move(board, x, y, player);
        draw_board(board);
        if (Iswinner(board))
        {
            game_over = true;
            cout << "Player " << player << " wins!" << endl;
        }
        else if (Isfull(board))
        {
            game_over = true;
            cout << "Tie!" << endl;
        }
        else
        {
            switch_player(player);
        }
    }
}
int main()
{
    char board[3][3] = {'_', '_', '_', '_', '_', '_', '_', '_', '_'};
    play_game(board);
    return 0;
}