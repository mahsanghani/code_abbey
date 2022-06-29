//
// Created by Ahsan Ghani on 2022-06-29.
//
#include <iostream>
int main(){
    constexpr bool condition {true};
    if constexpr (condition){
        std::cout << "Condition is true" << std::endl;
    }else{
        std::cout << "Condition is false" << std::endl;
    }
    return 0;
}