//
// Created by Ahsan Ghani on 2020-09-14.
//

#include <istream>
#include <iostream>
#include <string>
#include <vector>
#include <array>
using namespace std;

vector<string> input()
{
    int qty = 52;
    cout << "input data:" << endl;

    vector<string> set;
    for(int i=0;i<qty;i++){
        string num;
        cin >> num;
        set.push_back(num);
    }

    return set;
}

vector<string> process(vector<string> input_data)
{
    vector<string> suits = {"C", "D", "H", "S"};
    vector<string> ranks = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K"};
    vector<string> deck;
    vector<string> results;

    for(int i=0; i<suits.size(); i++){
        for(int j=0; j<ranks.size(); j++){
            string card;
            card.append(suits[i]);
            card.append(ranks[j]);
            deck.push_back(card);
        }
    }

    for(int i=0;i<input_data.size();i++){
        std::swap(deck[i],deck[stoi(input_data[i]) % 52]);
    }
    return deck;
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