//
// Created by Ahsan Ghani on 2022-08-24.
//
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define N 8

int solveKTUtil(int x,
                int y,
                int movei,
                int sol[N][N],
                int xmove[],
                int ymove[]);

int isSafe(int x,
           int y,
           int sol[N][N])
{
    return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
}

void printSolution(int sol[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << " " << setw(2) << sol[x][y] << " ";
        }
        cout << endl;
    }
}

int solveKT()
{
    int sol[N][N];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            sol[x][y] = -1;
        }
    }

    int xmove[8] = {2,1,-1,-2,-2,-1,1,2};
    int ymove[8] = {1,2,2,1,-1,-2,-2,-1};

    sol[0][0] = 0;

    if (solveKTUtil(0,0,1,sol,xmove,ymove) == 0)
    {
        cout << "Solution does not exist";
        return 0;
    }
    else
    {
        printSolution(sol);
    }

    return 1;
}

int solveKTUtil(int x,
                int y,
                int movei,
                int sol[N][N],
                int xmove[8],
                int ymove[8])
{
    int k, next_x, next_y;
    if (movei == N*N)
    {
        return 1;
    }

    for (k = 0; k < 8; k++)
    {
        next_x = x + xmove[k];
        next_y = y + ymove[k];
        if (isSafe(next_x, next_y, sol))
        {
            sol[next_x][next_y] = movei;
            if (solveKTUtil(next_x,
                            next_y,
                            movei+1,
                            sol,
                            xmove,
                            ymove) == 1)
            {
                return 1;
            }
            else
            {
                sol[next_x][next_y] = -1;
            }
        }
    }
    return 0;
}

int main()
{
    solveKT();
    return 0;
}
