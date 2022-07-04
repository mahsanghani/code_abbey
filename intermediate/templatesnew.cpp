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
    int x{5};
    int y{7};
    int* p_x(&x);
    int* p_y{&y};
    auto result = maximum(x,y);
    auto result2 = maximum(p_x,p_y);
    cout << "result: " << result << endl;
    cout << "result2: " << result2 << endl;
    return 0;
}