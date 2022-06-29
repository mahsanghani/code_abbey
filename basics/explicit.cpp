//
// Created by Ahsan Ghani on 2022-06-28.
//
#include <iostream>

int main(){
    double x { 12.5 };
    double y { 34.6};
    int sum = x + y;
    std::cout << "The sum  is : " << sum << std::endl;
    sum = static_cast<int>(x) + static_cast<int>(y) ;
    std::cout << "The sum  is : " << sum << std::endl;
    sum =  static_cast<int> (x + y);
    std::cout << "Sum up then cast, result : " << sum << std::endl;
    double PI {3.14};
    int int_pi = static_cast<int>(PI);
    std::cout << "PI : " << PI << std::endl;
    std::cout << "int_pi : " << int_pi << std::endl;
    return 0;
}