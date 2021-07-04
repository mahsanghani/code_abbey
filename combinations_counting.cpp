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

unsigned int factorial(unsigned int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
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

vector<unsigned long long> process(vector<vector<int>>data)
{
    vector<unsigned long long> totals;
    for (int i = 0; i < data.size(); i++)
    {
        unsigned long long total = 1;
        int n = data[i][0];
        int k = data[i][1];
        int delta = n - k;
        for (int j = 0; j < delta + 1; j++)
        {
            int new_n = n - j;
            total *= (new_n);
        }
        total /= (factorial(k) * factorial(n - k));
        totals.push_back(total);
    }
    return totals;
}

void output(vector<unsigned long long> totals)
{
    cout << "\nanswer: " << endl;
    for (int i = 0; i < totals.size(); i++)
    {
        cout << totals[i] << " ";
    }
}

int main(void)
{
    auto data = input();
    auto result = process(data);
    output(result);
    return 0;
}