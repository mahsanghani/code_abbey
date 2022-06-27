//
// Created by Ahsan Ghani on 2020-09-10.
//

#include <istream>
#include <iostream>
#include <vector>
#include <array>
#include <stack>
using namespace std;

vector<string> input(int &qty, int &shift)
{
    cout << "input data:" << endl;
    cin >> qty >> shift;
    cin.clear();
    cin.ignore();
    vector<string> set;
    int len = 128;

    for (int i = 0; i < qty; i++)
    {
        char *s = (char *)malloc( sizeof(char) * ( len + 1 ) );
        cin.getline(s, 128);
        set.emplace_back(s);
        delete[](s);
    }
    return set;
}

vector<string> process(vector<string> input_data, int &qty, int &shift)
{
//    vector<string> shifted;
//    cout << input_data.size() << endl;
    for (int i = 0; i < input_data.size(); i++)
    {
//        cout << input_data[i] << endl;
        for (int j=0;j<input_data[i].length();j++){
            if(input_data[i][j] >= 'A' && input_data[i][j]<='Z'){
                input_data[i][j] -= 'A';
                input_data[i][j] = (input_data[i][j] - shift + 26)%26;
                input_data[i][j] += 'A';
            }
        }
    }
    return input_data;
}

void output(vector<string> shifted)
{
    for (int i = 0; i < shifted.size(); i++)
    {
        {
            cout << shifted[i] << " ";
        }
    }
}

int main()
{
    int qty, shift;
    auto data = input(qty,shift);
    auto set = process(data,qty,shift);
    output(set);

    return 0;
}