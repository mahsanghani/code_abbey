//
// Created by Ahsan Ghani on 2022-07-25.
//

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <valarray>
#include <algorithm>
using namespace std;

bool enough(vector<int> &nums, int &m, int &length, int distance)
{
    int i, j, k = 0;
    while (i < length || j < length)
    {
        while (j < length && nums[j]-nums[i] <= distance)
        {
            j++;
        }
        k += j-i-1;
        i++;
    }
    return (k >= m);
}

int smallestDistancePair(vector<int> nums, int m)
{
    sort(nums.begin(), nums.begin());
    int length = nums.size();
    int left = 0;
    int right = nums.back() - nums[0];

    while (left < right)
    {
        int middle = left + (right - left) / 2;
        if (enough(nums, m, length, middle))
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
