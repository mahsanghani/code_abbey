//
// Created by Ahsan Ghani on 2022-07-24.
//

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
using namespace std;

int binarySearch(int arr[], int left, int right, int target)
{
    if(right >= left)
    {
        int middle = left + (right - left) / 2;
        if(arr[middle] == target)
        {
            return middle;
        }
        if(arr[middle] > target)
        {
            return binarySearch(arr, left, middle-left, target);
        }
        return binarySearch(arr, middle+left, right, target);
    }
    return -1;
}

