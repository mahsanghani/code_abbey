//
// Created by Ahsan Ghani on 2020-09-12.
//

#include <istream>
#include <iostream>
#include <vector>
#include <array>
#include <math.h>
#include <iomanip>

using namespace std;

vector<vector<int>> input()
{
    int qty;
    cout << "input data:" << endl;
    cin >> qty;
    cin.clear();
    cin.ignore();
    vector<vector<int>> all_sets;

    for (int i = 0; i < qty; i++)
    {
        vector<int> set;
        int a,b,c,d,e,f;
        cin >> a >> b >> c >> d >> e >> f;
        set.push_back(a);
        set.push_back(b);
        set.push_back(c);
        set.push_back(d);
        set.push_back(e);
        set.push_back(f);
        all_sets.push_back(set);
    }
    return all_sets;
}

vector<double> process(vector<vector<int>> input_data)
{
    vector <double> results;
    for(int i=0;i<input_data.size();i++){
        double a,b,c,s,area;
        a = sqrt(pow(abs(input_data[i][3]-input_data[i][1]),2) + pow(abs(input_data[i][2]-input_data[i][0]),2));
        b = sqrt(pow(abs(input_data[i][5]-input_data[i][3]),2) + pow(abs(input_data[i][4]-input_data[i][2]),2));
        c = sqrt(pow(abs(input_data[i][5]-input_data[i][1]),2) + pow(abs(input_data[i][4]-input_data[i][0]),2));
        s = (a+b+c)/2;
        area = sqrt(s*(s-a)*(s-b)*(s-c));
        results.push_back(area);
    }

    return results;
}

void output(vector<double> results)
{
    for (int i = 0; i < results.size(); i++)
    {
        if (i == results.size() - 1)
        {
            cout << std::setprecision(9) << results[i];
        }
        else
        {
            cout << std::setprecision(9) << results[i] << " ";
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