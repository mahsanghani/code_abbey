//
// Created by Ahsan Ghani on 2022-07-24.
//

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
using namespace std;

int binarySearch(vector<int> v, int target)
{
    int low = 0;
    int high = v.size() - 1;
    int middle = 0;

    while(high - low > 1)
    {
        middle = (high + low) / 2;
        if(v[middle] < target)
        {
            low = middle + 1;
        }
        else
        {
            high = middle;
        }
    }

    if(v[low] == target)
    {
        cout << "Found" << " At Index " << low << endl;
    }
    else if(v[high] == target)
    {
        cout << "Found" << " At Index " << high << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }
}

int main()
{
    vector<int> v = {1,2,3,4,5,6};
    int target = 1;
    binarySearch(v,target);
    target = 6;
    binarySearch(v,target);
    target = 10;
    binarySearch(v,target);
    return 0;
}
