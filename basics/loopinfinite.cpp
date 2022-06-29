//
// Created by Ahsan Ghani on 2022-06-29.
//
#include <iostream>
int main(){
    //Infinite loop : for loop
    for(size_t i{};true ; ++i){
        std::cout << i <<  " : I love C++" << std::endl;
    }

    //Infinite loop : while loop
    size_t i{0};
    while(true){
        std::cout << i  << " : I love C++" << std::endl;
        ++i;
    }

    //Infinite loop : do while loop
    size_t j{0};
    do{
        std::cout << j  << " : I love C++" << std::endl;
        ++j;
    }while(true);

    return 0;
}