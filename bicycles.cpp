//
// Created by Ahsan Ghani on 2020-05-30.
//

#include <iostream>
#include <vector>
#include <iomanip>
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
    vector<double> distances;

    for (int i = 0; i < data.size(); i++)
    {
        //cout<<double(double(data[i][0])/(double(data[i][1])+double(data[i][2])))<<endl;
        distances.push_back(double(data[i][1]) * (double(data[i][0])/(double(data[i][1])+double(data[i][2]))));
    }

    return distances;
}

void output(vector<double> distances)
{
    cout << "answer: " << endl;
    for (int i = 0; i < distances.size(); i++)
    {
        cout << setprecision(12) << distances[i] << " ";
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