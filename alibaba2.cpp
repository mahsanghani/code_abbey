//
// Created by Ahsan Ghani on 2020-09-13.
//

#include <istream>
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <map>

using namespace std;

string input()
{
    cout << "input data:" << endl;
    int len = 1205;
    char *s = (char *)malloc( sizeof(char) * ( len + 1 ) );
    cin.getline(s, 1205);
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return s;
}

vector<string> process(string s)
{
    string word = "";
    vector<string> input_data;
    vector<string> results;
    map<string,int> wordCount;
    for(auto x : s){
        if(x == ' ' || x == '\0' || x == '\n'){
            input_data.push_back(word);
            word = "";
        }else{
            word += x;
        }
    }

    for (int i = 0; i < input_data.size(); i++)
    {
        ++wordCount[input_data[i]];
    }

    for (map<string,int>::iterator it = wordCount.begin();it != wordCount.end(); ++it){
        cout << it->first << " " << it->second << endl;
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