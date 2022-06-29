//
// Created by Ahsan Ghani on 2022-06-29.
//
#include <iostream>

int main(){

    for(double multiplier{4}; auto i : {1,2,3,4,5,6,7,8,9,10}){
        std::cout << "result : " << ( i * multiplier) << std::endl;
    }

    return 0;
}