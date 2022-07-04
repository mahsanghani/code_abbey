//
// Created by Ahsan Ghani on 2022-07-04.
//
#include <iostream>
#include <string>
using namespace std;

//template <typename T>
//T maximum(T a, T b){
//    return (a>b)? a:b;
//}

template <typename T>
const T& maximum(const T& a, const T& b);

int main(){
    double a{23.5};
    double b{51.2};

    cout << "Out - &a: " << &a << endl;
    auto result = maximum(a,b);
    cout << "Out - &a: " << &a << endl;

    return 0;
}

template <typename T> const T& maximum(const T& a, const T& b){
    cout << "In - &a: " << &a << endl;
    return (a>b) ? a : b;
}

template <typename T> T maximum(T a, T b){
    cout << "In - &a: " << &a << endl;
    return (a>b) ? a : b;
}