//
// Created by Ahsan Ghani on 2022-08-24.
//
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define N 4

bool solveMazeUtil(int maze[N][N],
                   int x,
                   int y,
                   int sol[N][N]);

void pointSolution(int sol[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << " " << sol[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int maze[N][N], int x, int y)
{
    if (x >= 0 && x < N && y >= 0  && y < N && maze[x][y] == 1)
    {
        return true;
    }
    return false;
}

bool solveMaze(int maze[N][N])
{
    int sol[N][N] = {{0,0,0,0},
                     {0,0,0,0},
                     {0,0,0,0},
                     {0,0,0,0}};
    if (solveMazeUtil(maze,0,0,sol) == false)
    {
        cout << "Solution doesn't exist";
        return false;
    }
    printSolution(sol);
    return true;
}



int main()
{
    int maze[N][N] = {{1,0,0,0},
                      {1,1,0,1},
                      {0,1,0,0},
                      {1,1,1,1}};

    solveMaze(maze);
    return 0;
}