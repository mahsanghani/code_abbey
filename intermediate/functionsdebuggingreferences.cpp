//
// Created by Ahsan Ghani on 2022-07-04.
//
#include <iostream>
using namespace std;

int& adjust(int& input);
int sum(int x, int y);

int main(int argc, char **argv){
    int a{10};
    int b{12};
    int summation = sum(a,b);
    cout<<"sum: "<<summation<<endl;
    return 0;
}

int& adjust(int& input){
    int adjustment{2};
    input += adjustment;
    return input;
}

int sum(int x, int y){
    int result = x+y;
    adjust(result);
    return result;
}