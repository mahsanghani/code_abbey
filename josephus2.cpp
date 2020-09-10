//
// Created by Ahsan Ghani on 2020-08-11.
//

#include <iostream>
using namespace std;

void input(int& n,int& k){
    cout << "input data:" << endl;
    cin >> n >> k;
}

int process(int n,int k)
{
    if(n==1){
        return 1;
    }else{
        return(process(n-1, k)+ k-1) % n+1;
    }
}

void output(int survivor)
{
    cout << "answer: " << endl << survivor << endl;
}

int main(void)
{
    int n,k;input(n,k);
    auto result = process(n,k);
    output(result);

    return 0;
}
