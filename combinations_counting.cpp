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

unsigned long long factorial(unsigned int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

# define MAX 200
long long triangle[MAX + 1][MAX + 1];
void makeTriangle() {
    int i, j;
    triangle[0][0] = 1;
    for(i = 1; i < MAX; i++) {
        triangle[i][0] = 1;
        for(j = 1; j <= i; j++) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }
}

long long C(int n, int r) {
    return triangle[n][r];
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
    makeTriangle();
    vector<unsigned long long> totals;
    for (int i = 0; i < data.size(); i++)
    {
        totals.push_back(C(data[i][0],data[i][1]));
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