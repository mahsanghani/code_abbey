//
// Created by Ahsan Ghani on 2020-08-11.
//

#include <iostream>
using namespace std;

int josephus(int n,int k){
    if(n==1)
        return 1;
    else
        return(josephus(n-1,k)+ k-1) % n+1;

}

int main(void)
{
    int n,k;
    cout << "input data:" << endl;
    cin >> n >> k;
    cout << "answer:" << josephus(n,k);
    return 0;
}
