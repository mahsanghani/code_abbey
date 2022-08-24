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
