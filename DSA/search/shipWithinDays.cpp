//
// Created by Ahsan Ghani on 2022-07-25.
//

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <valarray>
#include <numeric>
using namespace std;

bool feasible(vector<int> &weights, int &time, int capacity)
{
    int days = 1;
    int total = 0;
    for (auto weight: weights)
    {
        total += weight;
        if (total > capacity)
        {
            total = weight;
            days += 1;
            if (days > time)
            {
                return false;
            }
        }
    }
    return true;
}


int shipWithinDays(vector<int> weights, int time)
{
    int left = *max_element(weights.begin(), weights.end());
    int right = accumulate(weights.begin(), weights.end(), 0);

    while (left < right)
    {
        int middle = left + (right - left) / 2;
        if (feasible(weights, time, middle))
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