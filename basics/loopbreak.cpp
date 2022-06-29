//
// Created by Ahsan Ghani on 2022-06-29.
//
#include <iostream>

int main(){
    // break and continue : for loops
    const size_t COUNT{20};
    for(size_t i{0} ; i < COUNT ; ++i ){
        if(i==5)
            continue;
        if(i == 11)
            break; // Breaks out of the loop
        std::cout << "i : " << i << std::endl;
    }
    std::cout << "Loop done!" << std::endl;

    // break and continue : while loop
    size_t i{0};
    while (i < 20){
        if(i==5){
            ++i;
            continue;
        }
        if(i==11)
            break;
        std::cout << "i : " << i << std::endl;
        ++i;
    }
    std::cout << "Loop done!" << std::endl;

    //break and continue : do while loop
    size_t j{0};

    do{
        if(j==5){
            ++j;
            continue;
        }

        if(j==11)
            break;


        std::cout << "i : " << j << std::endl;
        ++j;

    }while(j <20);

    return 0;
}