//
// Created by Ahsan Ghani on 2022-07-25.
//

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
using namespace std;

int searchInsert(vector<int> nums, int target)
{
    int left = 0;
    int right = nums.size();
    while(left < right)
    {
        int middle = left + (right - left) / 2;
        if(nums[middle] >= target)
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
