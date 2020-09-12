//
// Created by Ahsan Ghani on 2020-09-10.
//

#include <istream>
#include <iostream>
#include <vector>
#include <array>
#include <stack>
#include <bitset>
using namespace std;

vector<int> input()
{
    int qty;
    cout << "input data:" << endl;
    cin >> qty;
    vector<int> set;
    for(int i=0;i<qty;i++){
        int num;
        cin >> num;
        set.push_back(num);
    }
    return set;
}

vector<int> process(vector<int> input_data)
{
    vector <int> counts;
   for(int i=0;i<input_data.size();i++){
    bitset<32> binaryNum(input_data[i]);
   counts.push_back(binaryNum.count());
   }
   return counts;
}


void output(vector<int> set)
{
    for (int i = 0; i < set.size(); i++)
    {
        if (i == set.size() - 1)
        {
            cout << set[i];
        }
        else
        {
            cout << set[i] << " ";
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