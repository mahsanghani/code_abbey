//
// Created by Ahsan Ghani on 2022-06-27.
//
#include <iostream>
#include <string>

int main(){
//    Data input
    int age1;
    std::string name;
    std::cout << "Please type your name and age : " << std::endl;
    //std::cin >> name;
    //std::cin >> age1;
    std::cin >> name >> age1;
    std::cout << "Hello " << name << " you are " << age1 << " years old!" << std::endl;
    return 0;
}