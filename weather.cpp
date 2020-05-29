//
// Created by Ahsan Ghani on 2020-05-29.
//

#include <iostream>
#include <sstream>
#include <vector>
#include <array>
#include <string>
#include <map>
#include <math.h>
#include <iomanip>
using namespace std;

vector<double> input(int& qty)
{
    double f;
    vector<double> data;
    cout << "input data:" << endl;
    cin >> qty;

    for (int i = 0; i < qty; i++)
    {
        cin >> f;
        data.push_back(f);
    }
    return data;
}

vector<double> process(vector<double>data)
{
    int a=0;
    int b=a+1;
    int c=b+1;
    vector<double> smooth;
    smooth.push_back(data[0]);

    for (int i = 1; i < data.size()-1; i++)
    {
        smooth.push_back((data[a]+data[b]+data[c])/3);
        a++;b++;c++;
    }
    smooth.push_back(data.back());

    return smooth;
}

void output(vector<double> smooth)
{
    cout << "answer: " << endl;
    for (int i = 0; i < smooth.size(); i++)
    {
        cout << setprecision(12) << smooth[i] << " ";
    }
}

int main(void)
{
    int qty;
    auto data = input(qty);
    auto result = process(data);
    output(result);

    return 0;
}