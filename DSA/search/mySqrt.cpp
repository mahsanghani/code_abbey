//
// Created by Ahsan Ghani on 2022-07-25.
//

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
using namespace std;

int mySqrt(int x)
{
    int left = 0;
    int right = x;

    while(left < right)
    {
        int middle = left + (right - left) / 2;
        if(middle*middle <= x)
        {
            left = middle + 1;
        }
        else
        {
            right = middle;
        }
    }
    return left-1;
}