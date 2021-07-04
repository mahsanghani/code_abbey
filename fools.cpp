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

vector<int> process(vector<vector<int>>data)
{
    int total = 0;
    vector<int> totals;
    for (int i = 0; i < data.size(); i++)
    {
        for (int j = 0; j < data[i].size(); j++)
        {
            total += data[i][j]*data[i][j];
        }
        totals.push_back(total);
        total = 0;
    }
    return totals;
}

void output(vector<int> totals)
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
