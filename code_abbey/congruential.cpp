//
// Created by Ahsan Ghani on 2020-05-30.
//

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> input(int& a, int& b, int& c, int&d, int&e, int& qty)
{
    vector<int> one_set;
    vector<vector<int>> all_sets;

    cout << "input data:" << endl;
    cin >> qty;
    for (int i = 0; i < qty; i++)
    {
        cin >> a >> b >> c >> d >> e;
        one_set.push_back(a);
        one_set.push_back(b);
        one_set.push_back(c);
        one_set.push_back(d);
        one_set.push_back(e);

        all_sets.push_back(one_set);

        one_set.clear();
    }

    return all_sets;
}

vector<int> process(vector<vector<int>>data)
{
    vector<int> savings;

    for (int i = 0; i < data.size(); i++)
    {
        int X1=0;
        auto A = int(data[i][0]);
        auto C = int(data[i][1]);
        auto M = int(data[i][2]);
        auto X0 = int(data[i][3]);
        auto N = int(data[i][4]);

        for(int j = 0;j<N;j++)
        {
            X1 = (A*X0 + C)%M;
            X0=X1;
        }
        savings.push_back(X1);
    }
    return savings;
}

void output(vector<int> savings)
{
    cout << "answer: " << endl;
    for (int i = 0; i < savings.size(); i++)
    {
        cout << savings[i] << " ";
    }
}

int main(void)
{
    int a, b, c, d, e, qty;
    auto data = input(a, b, c, d, e, qty);
    auto result = process(data);
    output(result);

    return 0;
}