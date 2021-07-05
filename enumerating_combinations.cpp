//
// Created by Ahsan Ghani on 2021-07-04.
//

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void split(const string& string_in,
           char delim,
           vector<int>& tokens_out)
{
    istringstream iss(string_in);
    string token;
    while (getline(iss, token, delim)) {
        tokens_out.push_back(stoi(token));
    }
}

vector<vector<int>> input()
{
    string str_qty;
    vector<int> one_set;
    vector<vector<int>> all_sets;
    cout << "input data:" << endl;
    getline(cin, str_qty, '\n');
    int qty = stoi(str_qty);
    for (int i = 0; i < qty; i++)
    {
        string temp_string;
        getline(cin, temp_string, '\n');
        split(temp_string, ' ',one_set);
        all_sets.push_back(one_set);
        one_set.clear();
    }
    return all_sets;
}

int compare (const void *a, const void * b)
{
    return ( *(char *)a - *(char *)b );
}

void swap (char* a, char* b)
{
    char t = *a;
    *a = *b;
    *b = t;
}

int findCeil (char str[], char first, int l, int h)
{
    int ceilIndex = l;
    for (int i = l+1; i <= h; i++)
        if (str[i] > first && str[i] < str[ceilIndex])
            ceilIndex = i;
    return ceilIndex;
}

int fact(int n)
{
    if (n <= 1)
        return 1;
    return n * fact(n - 1);
}

int nPr(int n, int r)
{
    return fact(n) / fact(n - r);
}

string sortedPermutations ( char str[], int n, int k, int i )
{
    char all_perms[16] =  {};
    for(int counter = 0; counter < sizeof(all_perms); counter++)
    {
        cout << str << endl;
        int j;
        for ( j = k - 2; j >= 0; --j ) {
            if (str[j] < str[j + 1]) {
                break;
            }
        }
        if ( j == -1 ) {
            break;
        }
        else
        {
            int ceilIndex = findCeil( str, str[j], j + 1, k - 1 );
            swap( &str[j], &str[ceilIndex] );
            qsort( str + j + 1, k - j - 1, sizeof(str[0]), compare );
        }
    }
}

vector<string> process(vector<vector<int>>data)
{
    vector<string> permutations;
    for (int j = 0; j < data.size(); j++)
    {
        char str[] = "ABCD";
        int n = data[j][0]; int k = data[j][1]; int i = data[j][2];
        permutations.push_back(sortedPermutations(str,n,k,i));
    }
    return permutations;
}

void output(vector<unsigned long long> totals)
{
    cout << "\nanswer: " << endl;
    for (int i = 0; i < totals.size(); i++)
    {
        cout << totals[i] << " ";
    }
}

int main(void)
{
    auto data = input();
    auto result = process(data);
    output(result);
    return 0;
}