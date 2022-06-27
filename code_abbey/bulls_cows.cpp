//
// Created by Ahsan Ghani on 2020-02-02.
//

#include <cmath>
#include <iomanip>
#include <iostream>
#include <istream>
#include <map>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

vector<string> input(string& num, int& qty)
{
    cout << "input data:" << endl;
    cin >> num >> qty;
    vector<string> attempts;
    for (int i = 0; i < qty; i++) {
        string guess;
        cin >> guess;
        attempts.push_back(guess);
    }

    return attempts;
}

vector<string> process(string& num, int& qty, const vector<string>& attempts)
{    
    vector<string> hints;
    for (int i = 0; i < qty; i++) {

        int dig = 0; int pos = 0;

        for(int j = 0; j < attempts[i].size(); j++)
        {
            for (int k = 0; k < num.size(); k++)
            {
                if (attempts[i][j] == num[k] && j != k)
                {
                    dig++;
                }
            }
        }

        for (int l = 0; l < attempts[i].size(); l++)
        {
            if (num[l] == attempts[i][l])
            {
                pos++;
            }
        }

        hints.push_back(to_string(pos) + "-" + to_string(dig));
    }

    return hints;
}

void output(vector<string> set)
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
    int qty;
    string num;
    auto data = input(num, qty);
    auto set = process(num, qty, data);
    output(set);

    return 0;
}