//
// Created by Ahsan Ghani on 2022-07-06.
//
#include <iostream>
using namespace std;
#define MAX_CHARS 256

bool isIsomorphic(string s, string t)
{
    char map_s[128] = { 0 };
    char map_t[128] = { 0 };
    int len = s.size();
    for (int i = 0; i < len; ++i)
    {
        if (map_s[s[i]]!=map_t[t[i]]) return false;
        map_s[s[i]] = i+1;
        map_t[t[i]] = i+1;
    }
    return true;
}

int main()
{
    cout << isIsomorphic("aab","xxy") << endl;
    cout << isIsomorphic("aab","xyz") << endl;
    return 0;
}