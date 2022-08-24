//
// Created by Ahsan Ghani on 2022-08-24.
//
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define N 4

void printSolution(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << " " << board[i][j] << " ";
        }
        printf("\n");
    }
}

bool isSafe(int board[N][N], int row, int col)
{
    for (int i = 0; i < col; i++)
    {
        if (board[row][i])
        {
            return false;
        }
    }

    for ( int i = row, int j = col;
    i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }

    for ( int i = row, int j = col;
            j >= 0 && i < N; i++, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }

    return true;
}