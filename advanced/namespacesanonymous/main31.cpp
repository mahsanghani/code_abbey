//
// Created by Ahsan Ghani on 2022-08-11.
//
#include <iostream>

namespace{
    double add(double a, double b); // Declaration
}

int main(){

    double result = add(10.2,20.2);
    std::cout << "result : " << result << std::endl;

    return 0;
}

namespace{
    double add(double a, double b){
        return a + b;
    }
}