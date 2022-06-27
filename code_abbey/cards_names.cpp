//
// Created by Ahsan Ghani on 2020-09-14.
//

#include <istream>
#include <iostream>
#include <vector>
#include <array>
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

vector<string> process(vector<int> input_data)
{
    vector<string> suits = {"Clubs", "Spades", "Diamonds", "Hearts"};
    vector<string> ranks = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
    vector<string> results;

    for(int i=0;i<input_data.size();i++){
        string temp={};
        string suit_value = suits[input_data[i] / 13];
        string rank_value = ranks[input_data[i] % 13];
        temp.append(rank_value);
        temp.append("-of-");
        temp.append(suit_value);
        results.push_back(temp);
    }
    return results;
}


void output(vector<string> set)
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