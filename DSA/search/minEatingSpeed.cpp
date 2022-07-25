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

bool feasible(vector<int> &nums, int &hours, int speed)
{
    int total = 0;
    for (auto num: nums)
    {
        total += (num-1)/speed+1;
    }
    return total <= hours;
}


int minEatingSpeed(vector<int> nums, int hours)
{
    int left = *max_element(nums.begin(), nums.end());
    int right = accumulate(nums.begin(), nums.end(), 0);

    while (left < right)
    {
        int middle = left + (right - left) / 2;
        if (feasible(nums, hours, middle))
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
