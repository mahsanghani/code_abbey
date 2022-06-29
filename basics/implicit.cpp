//
// Created by Ahsan Ghani on 2022-06-28.
//
#include <iostream>

int main(){
    double price { 45.6 };
    int units {10};

    auto total_price = price * units; // units will be implicitly converted to double

    std::cout << "Total price : " << total_price << std::endl;
    std::cout << "sizeof total_price : " << sizeof(total_price) << std::endl;
    int x;
    double y {45.44};
    x = y; // double to int
    std::cout << "The value of x is : " << x << std::endl; // 45
    std::cout << "sizeof x : " << sizeof(x) << std::endl;// 4
    return 0;
}