//
// Created by Ahsan Ghani on 2022-07-15.
//
#include <iostream>

//Version making a little more sense for the task
template <typename T>
bool is_valid(T collection[], int threshold,size_t size)
{
    T sum{};
    for(size_t i{ 0 }; i < size; ++i) {
        sum += collection[i];
    }
    return (sum > threshold) ? true : false;
}

int main(){

    double temperatures[] {10.0,20.0,30.0,40.0,50.0,100.0};

    auto result = is_valid<double>(temperatures,200,std::size(temperatures));
    std::cout << std::boolalpha;
    std::cout << "result : " << result << std::endl;

    return 0;
}