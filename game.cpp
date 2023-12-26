#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

void draw_board(char **board, int n)
{

    for (int row = 0; row < n; row++)
    {
        cout << "  ";
        for (int col = 0; col < n; col++)
        {
            cout << board[row][col];
            if (col != n - 1)
            {
                cout << "  |  ";
            }
            else
            {
                cout << endl;
            }
        }
        if (row != n - 1)
        {
            for (int j = 0; j < 2; j++)
            {
                for (int i = 0; i < n; i++)
                {
                    if (j == 0)
                    {
                        cout << "_____";
                        if (i != n - 1)
                        {
                            cout << "|";
                        }
                    }
                    else
                    {
                        cout << "     ";
                        if (i != n - 1)
                        {
                            cout << "|";
                        }
                    }
                }
                cout << endl;
            }
        }
    }
}

// void draw_board(char **board, int n)
// {

//     for (int row = 0; row < n; row++)
//     {
//         cout << "  ";
//         for (int col = 0; col < n; col++)
//         {
//             cout << board[row][col];
//             if (col != n - 1)
//             {
//                 cout << "  |  ";
//             }
//             else
//             {
//                 cout << endl;
//             }
//         }
//         if (row != n - 1)
//         {

//             cout << "_____|_____|_____" << endl;
//             cout << "     |     |     " << endl;
//         }
//     }
// }

void get_position(char **board, int n, int &row, int &col, char player)
{
    int a = row;
    int b = col;
    do
    {
        cout << "Enter the position of row and column" << endl;
        cout << "row (0 to n-1) : ";
        cin >> a;
        cout << "column (0 to n-1) : ";
        cin >> b;
        if (a > n - 1 || b > n - 1 || a < 0 || b < 0)
        {
            system("cls");
            cout << "Player " << player << "'s turn" << endl;
            draw_board(board, n);
            cout << "\nInvalid position! try again\n"
                 << endl;
        }
        else
        {
            row = a;
            col = b;
        }
    } while (a > n - 1 || b > n - 1 || a < 0 || b < 0);
}

bool Iswinner(char **board, int n)
{
    // check rows
    for (int row = 0; row < n; row++)
    {
        bool win = true;
        for (int col = 0; col < n - 1; col++)
        {
            if (board[row][col] != board[row][col + 1] || board[row][col] == '_')
            {
                win = false;
                break;
            }
        }
        if (win)
        {
            return true;
        }
    }
    // check cols
    for (int col = 0; col < n; col++)
    {
        bool win = true;
        for (int row = 0; row < n - 1; row++)
        {
            if (board[row][col] != board[row + 1][col] || board[row][col] == '_')
            {
                win = false;
                break;
            }
        }
        if (win)
        {
            return true;
        }
    }
    // check diagnonals
    bool win = true;
    for (int i = 0; i < n - 1; i++)
    {
        if (board[i][i] != board[i + 1][i + 1] || board[i][i] == '_')
        {
            win = false;
            break;
        }
    }
    if (win)
    {
        return true;
    }
    win = true;
    for (int i = 0; i < n - 1; i++)
    {
        if (board[i][n - 1 - i] != board[i + 1][n - 2 - i] || board[i][n - 1 - i] == '_')
        {
            win = false;
            break;
        }
    }
    if (win)
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

bool isAvailable(char **board, int &x, int &y)
{
    return board[x][y] == '_';
}

void make_move(char **board, int &x, int &y, char player)
{
    board[x][y] = player;
}

bool Isfull(char **board, int n)
{
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (board[row][col] == '_')
            {
                return false;
            }
        }

        return true;
    }
}

void play_game(char **board, int n)
{
    char player = 'X';
    bool game_over = false;
    int x, y;
    while (!game_over)
    {
        system("cls");
        cout << "Player " << player << "'s turn" << endl;
        draw_board(board, n);
        get_position(board, n, x, y, player);
        while (!isAvailable(board, x, y))
        {
            system("cls");
            cout << "Player " << player << "'s turn" << endl;
            draw_board(board, n);
            cout << "Position is already taken! try again" << endl;
            get_position(board, n, x, y, player);
        }
        make_move(board, x, y, player);
        draw_board(board, n);
        if (Iswinner(board, n))
        {
            game_over = true;
            cout << "Player " << player << " wins!" << endl;
        }
        else if (Isfull(board, n))
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
    int n;

    cout << "Welcome to Tic Tac Toe" << endl;
    cout << "enter the size of the board (min 3) : ";
    cin >> n;
    while (n < 3)
    {
        system("cls");
        cout << "Welcome to Tic Tac Toe" << endl;
        cout << "enter the size of the board (min 3) : ";
        cout << endl
             << "Invalid size! try again" << endl;
        cin >> n;
    }

    char **board = new char *[n];
    for (int i = 0; i < n; i++)
    {
        board[i] = new char[n];
        for (int j = 0; j < n; j++)
        {
            board[i][j] = '_';
        }
    }

    play_game(board, n);
    return 0;
}