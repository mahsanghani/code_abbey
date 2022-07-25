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

bool feasible(vector<int> &nums, int &m, int &k, int days)
{
    int bouquets = 0;
    int flowers = 0;
    for (auto num : nums)
    {
        if (num > days)
        {
            flowers = 0;
        }
        else
        {
            bouquets += (flowers + 1) / k;
            flowers = (flowers + 1) % k;
        }
    }
    return bouquets >= m;
}


int minDays(vector<int> nums, int m, int k)
{
    if(nums.size() < m * k)
    {
        return -1;
    }

    int left = 1;
    int right = *max_element(nums.begin(), nums.end());

    while (left < right)
    {
        int middle = left + (right - left) / 2;
        if (feasible(nums, m, k,middle))
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
