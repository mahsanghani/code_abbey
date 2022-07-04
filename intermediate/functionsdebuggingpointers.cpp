//
// Created by Ahsan Ghani on 2022-07-04.
//
#include <iostream>
using namespace std;

double sum(double array[], auto count){
    double sum{};
    for(size_t i{};i<count;++i){
        sum+=array[i];
    }
    return sum;
}

int main(int argc, char **argv){
    double numbers[] {10.0,20.0,30.0,40.0,50.0};
    double total = sum(numbers,size(numbers));
    cout<<"sum: "<<total<<endl;
    return 0;
}