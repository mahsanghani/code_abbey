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

vector<string> input()
{
    cout << "input data:" << endl;

    int qty=300;
    char *word = "";
    vector<string> set;
    for(int i=0; i<qty; i++){
        cin.getline(word,3,' ');
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\0');
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (word=="end"){
            break;
        }
        cin.clear();
        cin.ignore();
        set.push_back(word);
        cout << set[i]<<endl;
    }
    cin.clear();
    cin.ignore();
    return set;
}

vector<string> process(vector<string> input_data)
{
    string word = "";
    vector<string> results;
    map<string,int> wordCount;

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