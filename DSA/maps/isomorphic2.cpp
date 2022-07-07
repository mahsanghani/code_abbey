//
// Created by Ahsan Ghani on 2022-07-06.
//
#include <iostream>
using namespace std;
#define MAX_CHARS 256

bool isIsomorphic(string a, string b)
{
    int m = a.length();
    int n = b.length();

    if(m!=n)
    {
        return false;
    }

    int count[MAX_CHARS] = {0};
    int dcount[MAX_CHARS] = {0};

    for (int i=0;i<n;i++)
    {
        count[a[i] - 'a']++;
        dcount[b[i] - 'a']++;
    }

    for (int i=0;i<n;i++)
    {
        if(count[a[i] - 'a'] != dcount[b[i] - 'a'])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cout << isIsomorphic("aab","xxy") << endl;
    cout << isIsomorphic("aab","xyz") << endl;
    return 0;
}