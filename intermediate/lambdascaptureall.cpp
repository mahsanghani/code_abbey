//
// Created by Ahsan Ghani on 2022-07-04.
//
#include <iostream>

int main(){

    //Capture everything by value
    int a{42};

    auto func = [=](){
        std::cout << "Inner value : " << a << std::endl;
    };

    for(size_t i{} ; i < 5 ;++i){
        std::cout << "Outer value : " << a << std::endl;
        func();
        ++a;
    }


    //Capturing all reference
    int c{42};
    int d{5};

    auto func2 = [&](){
        std::cout << "Inner value : " << c << std::endl;
        std::cout << "Inner value(d) : " << d << std::endl;
    };

    for(size_t i{} ; i < 5 ;++i){
        std::cout << "Outer value : " << c << std::endl;
        func2();
        ++c;
    }

    return 0;
}