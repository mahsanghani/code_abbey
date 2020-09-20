//
// Created by Ahsan Ghani on 2020-09-14.
//
#include <istream>
#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <map>

using namespace std;

map<string,int> input()
{
    string word;
    map<string,int> counts;
    cout << "input_data:" << endl;

    do{
        cin >> word;
        counts[word]++;
    }while(word.compare("end") !=0);

    return counts;
}

vector<string> process(map<string, int> input_data)
{
    vector<string> results;

    for(auto i=input_data.cbegin(); i != input_data.cend(); i++){
        if(i->second > 1){
            results.push_back(i->first);
        }
    }

    return results;
}

void output(vector<string> results)
{
    for (int i = 0; i < results.size(); i++)
    {
        if (i == results.size() - 1)
        {
            cout << results[i];
        }
        else
        {
            cout << results[i] << " ";
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