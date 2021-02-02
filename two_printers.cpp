//
// Created by Ahsan Ghani on 2020-02-01.
//

#include <cmath>
#include <iomanip>
#include <iostream>
#include <istream>
#include <map>
#include <math.h>
#include <vector>

using namespace std;

vector<vector<int>> input()
{
    int qty;
    cout << "input data:" << endl;
    cin >> qty;
    vector<int> set;
    vector<vector<int>> all_sets;
    for (int i = 0; i < qty; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        set.push_back(a);
        set.push_back(b);
        set.push_back(c);
        all_sets.push_back(set);
        set.clear();
    }

    return all_sets;
}

vector<double> process(const vector<vector<int>>& input_data)
{
    vector<double> time;
    for (int i = 0; i < input_data.size(); i++) {
        double x = input_data[i][0];
        double y = input_data[i][1];
        double n = input_data[i][2];

        double sum = x + y;
        double min_ceil = ceil((min(x, y) / sum) * n);
        double max_ceil = ceil((max(x, y) / sum) * n);
        double least = min(x, y);
        double most = max(x, y);
        
        double a = ceil((max(x, y) / float(x+y)) * n) * min(x,y);
        double b = ceil((min(x, y) / float(x+y)) * n) * max(x,y);

        double _time = min(a, b);

        time.push_back(_time);
    }

    return time;
}

void output(vector<double> set)
{
    for (int i = 0; i < set.size(); i++)
    {
        if (i == set.size() - 1)
        {
            cout << setprecision(15) << set[i];
        }
        else
        {
            cout << setprecision(15) << set[i] << " ";
        }
    }
}

int main()
{
    auto data = input();
    auto set = process(data);
    output(set);

    return 0;
}
