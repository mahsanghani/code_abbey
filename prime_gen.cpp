//
// Created by Ahsan Ghani on 2020-09-18.
//

#include <istream>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>

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
    cout << "thanks, thinking..." << endl;
    //int max = 15485867;
    int max = 3000017;
    vector<int> primes;
    vector<bool> is_prime(max,true);
    map <int,int> all_primes;
    int n=0;
    for(int i=2;i<sqrt(max);i++){
        if(is_prime[i]){
            for(int j=pow(i,2);j<max; j+=(n*i))
                is_prime[j] = false;
                n++;
        }
    }
    for(int j=0;j<max;j++){
        if(is_prime[j])
        {
            all_primes[j]++;
        }
    }
    primes.reserve(input_data.size());
    for(int k=0;k<input_data.size();k++){
        primes.push_back(all_primes[input_data[k]]);
    }
    return primes;
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