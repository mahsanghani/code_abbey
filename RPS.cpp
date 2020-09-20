//
// Created by Ahsan Ghani on 2020-09-12.
//

#include <istream>
#include <iostream>
#include <vector>
#include <array>
//#include <boost/algorithm/string.hpp>

using namespace std;

vector<string> input()
{
    int qty;
    cout << "input data:" << endl;
    cin >> qty;
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

vector<int> process(vector<string> input_data)
{
    vector<int> results;
    for (int i = 0; i < input_data.size(); i++)
    {
        int p1=0; int p2=0;
        vector<string> match={};
//        std::istringstream ss(input_data[i]);
//        boost::split(match, input_data[i], boost::is_any_of(' '));
        string word="";
        for(auto x : input_data[i]){
//            cout << x << " ";
            if(x == ' ' || x == '\0' || x == '\n'){
//                cout<< word<<endl;
                match.push_back(word);
                word = "";
            }else{
                word += x;
            }
        }match.push_back(word);  // fence post scenario for last round
//        cout << match.size() << endl;
        for(int j=0;j<match.size();j++){
            if(match[j][0] == 'P' && match[j][1] == 'R'){p1++;}
            if(match[j][0] == 'P' && match[j][1] == 'S'){p2++;}
            if(match[j][0] == 'R' && match[j][1] == 'P'){p2++;}
            if(match[j][0] == 'R' && match[j][1] == 'S'){p1++;}
            if(match[j][0] == 'S' && match[j][1] == 'R'){p2++;}
            if(match[j][0] == 'S' && match[j][1] == 'P'){p1++;}
            if(match[j][0] == 'R' && match[j][1] == 'R'){}
            if(match[j][0] == 'P' && match[j][1] == 'P'){}
            if(match[j][0] == 'S' && match[j][1] == 'S'){}
        }

        if(p1>p2){
            results.push_back(1);
        }else if(p2>p1){
            results.push_back(2);
        }else{
            results.push_back(0);
        }
    }
    return results;
}

void output(vector<int> results)
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