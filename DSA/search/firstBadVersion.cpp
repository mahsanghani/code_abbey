//
// Created by Ahsan Ghani on 2022-07-25.
//

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
using namespace std;

int firstBadVersion(int n)
{
    int left = 0;
    int right = n;
    while(left < right)
    {
        int middle = left + (right - left) / 2;
        if isBadVersion(middle)
        {
            right = middle;
        }
        else
        {
            left = middle + 1;
        }
    }
    return left;
}