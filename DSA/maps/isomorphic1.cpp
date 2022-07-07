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

    bool marked[MAX_CHARS] = {false};

    int map[MAX_CHARS];
    memset(map,-1,sizeof(map));

    for(int i=0;i<n;i++)
    {
        if(map[a[i]]==-1)
        {
            if(marked[b[i]]==true)
            {
                return false;
            }

            marked[b[i]] = true;

            map[a[i]] = b[i];
        }
        else if(map[a[i]]!=b[i])
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