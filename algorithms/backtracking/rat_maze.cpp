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

