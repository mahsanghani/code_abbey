//
// Created by Ahsan Ghani on 2020-09-10.
//

#include <iostream>

using namespace std;

int bin_gap(int n){
    int max=-1;
    while(n){
        int count=-1;
        if(n&1!=0){
            n=n>>1;
            while(n && !(n&1)){
                count++;
                n=n>>1;
            }
        }else{
            n=n>>1;
        }
        if(max<count){
            max=count;
        }
    }
    return (max==-1)?-1:max+1;
}

int main(void){
    int num=1030;
    cout<<bin_gap(num);
    return 0;
}