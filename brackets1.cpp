//
// Created by Ahsan Ghani on 2020-08-12.
//

#include <istream>
#include <iostream>
#include <vector>
#include <array>
#include <stack>
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

vector<bool> process(vector<string> input_data)
{
    vector<bool> balanced;
    cout << input_data.size() << endl;
    for (int i = 0; i < input_data.size(); i++)
    {
        cout << input_data[i] << endl;
        stack<char> s;
        char x;
        bool flag = false;
        for (int j=0;j<input_data[i].length();j++){

            if(input_data[i][j] == '(' || input_data[i][j] == '{' || input_data[i][j] =='[' || input_data[i][j] =='<'){
                s.push(input_data[i][j]);
                continue;
            }
            if(s.empty() && (input_data[i][j] == '>'|| input_data[i][j] == ']'|| input_data[i][j] == '}'|| input_data[i][j] == ')'))
            {
                balanced.push_back(false);
                flag=true;
                break;
            }
            if(!s.empty()) {
                switch (input_data[i][j]) {
                    case ')':
                        x = s.top();
                        s.pop();
                        if (x == '{' || x == '[' || x == '<') {
                            balanced.push_back(false);
                            flag = true;
                        }
                        break;

                    case '}':
                        x = s.top();
                        s.pop();
                        if (x == '(' || x == '[' || x == '<') {
                            balanced.push_back(false);
                            flag = true;
                        }
                        break;

                    case ']':
                        x = s.top();
                        s.pop();
                        if (x == '(' || x == '{' || x == '<') {
                            balanced.push_back(false);
                            flag = true;
                        }
                        break;

                    case '>':
                        x = s.top();
                        s.pop();
                        if (x == '(' || x == '{' || x == '[') {
                            balanced.push_back(false);
                            flag = true;
                        }
                        break;
                }
                if (flag) { break; }
            }
        }
        if(s.empty() && !flag){
            balanced.push_back(true);
        }else if(!s.empty() && !flag){
            balanced.push_back(false);
        }
    }
    return balanced;
}

void output(vector<bool> balanced)
{
    for (int i = 0; i < balanced.size(); i++)
    {
        if (i == balanced.size() - 1)
        {
            cout << balanced[i];
        }
        else
        {
            cout << balanced[i] << " ";
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