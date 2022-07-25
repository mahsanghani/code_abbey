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

bool enough(int &m, int &n, int &k, int num)
{
    int count = 0;
    for (int i=0; i<m; i++)
    {
        int add = min(num/i, n);
        if (add == 0)
        {
            break;
        }
        count += add;
    }
    return (count >= k);
}


int findKthNumber(int m, int n, int k)
{
    int left = 1;
    int right = n*m;
    while (left < right)
    {
        int middle = left + (right - left) / 2;
        if (enough(m,n,k,middle))
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
