//
// Created by Ahsan Ghani on 2022-07-04.
//
#include <iostream>
using namespace std;

template <typename T, typename P>
auto maximum (T a, P b){
    return (a > b) ? a : b;
}

int main(){
    auto max1 = maximum('e', 33);
    cout << "max1: " << max1 << endl;
    cout << "size of max1: " << sizeof(max1) << endl;
    return 0;
}