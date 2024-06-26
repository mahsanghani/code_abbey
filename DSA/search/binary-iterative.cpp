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
    while(left<=right)
    {
        int middle = left + (right - left) / 2;
        if(arr[middle] == target)
        {
            return middle;
        }
        if(arr[middle] < target)
        {
            left = middle + 1;
        }
        if(arr[middle] > target)
        {
            right = middle - left;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {2,3,4,10,40};
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n-1, x);
    (result == -1)
    ? cout << "Element is not present in array"
    : cout << "Element is present at index " << result << endl;
    return 0;
}