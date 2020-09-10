//
// Created by Ahsan Ghani on 2020-08-11.
//

#include <istream>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> input(int& a, int& b, int& qty)
{
    vector<int> one_set;
    vector<vector<int>> all_sets;

    cout << "input data:" << endl;
    cin >> qty;
    for (int i = 0; i < qty; i++)
    {
        cin >> a >> b;
        one_set.push_back(a);
        one_set.push_back(b);

        all_sets.push_back(one_set);

        one_set.clear();
    }

    return all_sets;
}

vector<int> process(vector<vector<int>> input_data)
{
    vector<int> dice;
    for (int i = 0; i < input_data.size(); i++)
    {
        int dice1 = input_data[i][0] % 6;
        int dice2 = input_data[i][1] % 6;
        int sum = (dice1+1) + (dice2+1);
        dice.push_back(sum);
    }
    return dice;
}

void output(vector<int> dice)
{
    for (int i = 0; i < dice.size(); i++)
    {
        if (i == dice.size() - 1)
        {
            cout << dice[i];
        }
        else
        {
            cout << dice[i] << " ";
        }
    }
}

int main()
{
    int a,b,qty;
    auto data = input(a,b,qty);
    auto dice = process(data);
    output(dice);

    return 0;
}