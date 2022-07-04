//
// Created by Ahsan Ghani on 2022-07-04.
//
#include <iostream>
#include <string>
using namespace std;

template <typename T>
T maximum(T a, T b){
    return (a>b)? a:b;
}

int main(){
    int a{10};
    int b{23};
    double c{34.7};
    double d{23.4};
    string e{"hello"};
    string f{"world"};

    auto max = maximum<double>(a,b);
    cout << "max: " << max << endl;

    return 0;
}