//
// Created by Ahsan Ghani on 2020-05-30.
//

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<vector<int>> input(int& a, int& b, int& c, int& qty)
{
    vector<int> one_set;
    vector<vector<int>> all_sets;

    cout << "input data:" << endl;
    cin >> qty;
    for (int i = 0; i < qty; i++)
    {
        cin >> a >> b >> c;
        one_set.push_back(a);
        one_set.push_back(b);
        one_set.push_back(c);

        all_sets.push_back(one_set);

        one_set.clear();
    }

    return all_sets;
}

vector<double> process(vector<vector<int>>data)
{
    vector<double> savings;

    for (int i = 0; i < data.size(); i++)
    {
        auto P = double(data[i][0]);
        auto A = double(data[i][1]);
        auto r = double(data[i][2])/100;
        double time  = (log (A)-log (P))/(log (1+r));
        savings.push_back(ceil(time));
    }
    return savings;
}

void output(vector<double> savings)
{
    cout << "answer: " << endl;
    for (int i = 0; i < savings.size(); i++)
    {
        cout << savings[i] << " ";
    }
}

int main(void)
{
    int a, b, c, qty;
    auto data = input(a, b, c, qty);
    auto result = process(data);
    output(result);

    return 0;
}