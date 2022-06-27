//
// Created by Ahsan Ghani on 2022-06-27.
//
#include <iostream>
#include <string>

int main(){
    std::string full_name;
    int age3;
    std::cout << "Please type in your full name and age " << std::endl;
    std::getline(std::cin,full_name);
    std::cin >> age3;
    std::cout << "Hello " << full_name << " you are " << age3 << " years old!" << std::endl;
    return 0;
}