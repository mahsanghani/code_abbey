//
// Created by Ahsan Ghani on 2020-09-14.
//

// https://www.codeabbey.com/index/task_view/palindromes

#include <iostream>
#include <istream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <array>
#include <regex>
#include <iterator>
using namespace std;

vector<string> input()
{
    vector<string>all_sets;
    char qty[5], my_string[99];
    cout << "input data:" << endl;
    cin.getline(qty, 5);

    int qty2 = stoi(qty);

    for (int i = 0; i < qty2; i++)
    {
        cin.getline(my_string, 99);
        all_sets.push_back(my_string);
    }

    return all_sets;
}

string clean_up(string my_string)
{
    for (int i = 0; i < my_string.size(); i++)
    {
        if (my_string[i] < 'A' || my_string[i] > 'Z' &&
                                  my_string[i] < 'a' || my_string[i] > 'z')
        {
            my_string.erase(i, 1);
            i--;
        }
    }
    for (int i = 0; i < my_string.size(); i++)
    {
        if (my_string[i] >= 'A' && my_string[i] <= 'Z')
        {
            my_string[i] += 32;
        }
    }
    cout << my_string << endl;
    return my_string;
}

vector<char> process(vector<string> input_data)
{
    vector<char> verdict;
    for (int i = 0; i < input_data.size(); i++)
    {
        string my_string = clean_up(input_data[i]);
        if (equal(my_string.begin(), my_string.begin() + my_string.size() / 2, my_string.rbegin()))
        {
            char yes = 'Y';
            verdict.push_back(yes);
        }
        else
        {
            char no = 'N';
            verdict.push_back(no);
        }
    }

    return verdict;
}

void output(vector<char> verdict)
{
    cout << "answer: " << endl;
    for (int i = 0; i < verdict.size(); i++)
    {
        cout << verdict[i] << " ";
    }
}

int main(void)
{
    auto data = input();
    auto result = process(data);
    output(result);

    return 0;
}