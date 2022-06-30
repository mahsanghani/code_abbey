//
// Created by Ahsan Ghani on 2022-06-30.
//
#include <iostream>

int main(){
    int scores [] {1,2,5};
    int count { std::size(scores)}; // std::size( C++17)
    std::cout << "sizeof(scores) : " << sizeof(scores) << std::endl;
    std::cout << "sizeof(scores[0]) : " << sizeof(scores[0]) << std::endl;
    std::cout << "count : " << count << std::endl;
    int count2 {sizeof(scores)/sizeof(scores[0])};
    for(size_t i {0} ; i < count2 ; ++i){
        std::cout << "scores [" << i << "] : " << scores[i] << std::endl;
    }
    //Range based for loop
    for ( auto i : scores){
        std::cout << "value  : " << i << std::endl;
    }
    return 0;
}