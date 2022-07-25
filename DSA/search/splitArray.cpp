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

bool feasible(vector<int> &nums, int &m, int threshold)
{
    int count = 1;
    int total = 0;
    for (auto num: nums)
    {
        total += num;
        if (total > threshold)
        {
            total = num;
            count += 1;
            if (count > m)
            {
                return false;
            }
        }
    }
    return true;
}


int splitArray(vector<int> nums, int m)
{
    int left = *max_element(nums.begin(), nums.end());
    int right = accumulate(nums.begin(), nums.end(), 0);

    while (left < right)
    {
        int middle = left + (right - left) / 2;
        if (feasible(nums, m, middle))
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
