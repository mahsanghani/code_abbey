//
// Created by Ahsan Ghani on 2021-07-04.
//

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void split(const string& string_in,
           char delim,
           vector<int>& tokens_out)
{
    istringstream iss(string_in);
    string token;
    while (getline(iss, token, delim)) {
        tokens_out.push_back(stoi(token));
    }
}

vector<vector<int>> input()
{
    string str_qty;
    vector<int> one_set;
    vector<vector<int>> all_sets;
    cout << "input data:" << endl;
    getline(cin, str_qty, '\n');
    int qty = stoi(str_qty);
    for (int i = 0; i < qty; i++)
    {
        string temp_string;
        getline(cin, temp_string, '\n');
        split(temp_string, ' ',one_set);
        all_sets.push_back(one_set);
        one_set.clear();
    }
    return all_sets;
}

template<typename T>
void pretty_print(vector<vector<char>>& all, const T& c, int combo)
{
    int n = c.size();
    for (int i = 0; i < n; ++i) {
        if ((combo >> i) & 1)
        {
            cout << c[i] << endl;
            // all[i].push_back(c[i]);
        }
        else
        {
            break;
        }
    }
}

template<typename T>
void combo(vector<vector<char>>& all, const T& c, int k)
{
    int n = c.size();
    int combo = (1 << k) - 1;       // k bit sets
    while (combo < 1<<n) {

        pretty_print(all, c, combo);

        int x = combo & -combo;
        int y = combo + x;
        int z = (combo & ~y);
        combo = z / x;
        combo >>= 1;
        combo |= y;
    }
}

vector<char> specificElementInSortedCombinations(vector<char> input, int n, int k, int i )
{
    vector<vector<char>>all_perms={{}};
    vector<char> subset = {input.begin(), input.begin()+n};
    combo(all_perms,subset,k);
    return all_perms[i];
}

vector<vector<char>> process(vector<vector<int>>data)
{
    vector<vector<char>> combinations;
    for (int j = 0; j < data.size(); j++)
    {
        vector<char>input = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
        int n = data[j][0]; int k = data[j][1]; int i = data[j][2];
        combinations.push_back(specificElementInSortedCombinations(input, n, k, i));
    }
    return combinations;
}

void output(vector<vector<char>> combos)
{
    cout << "\nanswer: " << endl;
    for (int i = 0; i < combos.size(); i++)
    {
        for(int j=0; j<combos[i].size(); j++)
        {
            cout << combos[i][j];
        }
        cout << endl;
    }
}

int main(void)
{
    auto data = input();
    auto result = process(data);
    output(result);
    return 0;
}
