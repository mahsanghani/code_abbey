//
// Created by Ahsan Ghani on 2022-06-29.
//
#include <iostream>
int main(){
    int condition{2};
    int my_var{4};
    switch (int data{7}; condition)
    {
//      int x{9};
// Never going to run
        int x;
        case 0 :
            //int y {5};
            int y;
            x = 6;
            x++;
            //z =6;
            std::cout << "x : " << x << std::endl;
            std::cout << "Statement1" << std::endl;
            std::cout << "Statement2" << std::endl;
            break;
        case 1 :
            int z;
            my_var++;
            y = 5;
            std::cout << "y : " << y << std::endl;
            std::cout << "Statement3" << std::endl;
            std::cout << "Statement4" << std::endl;
            break;
        default:
            int u;
            z = 10;
            std::cout << "x : " << x << std::endl;
            std::cout << "y : " << y << std::endl;
            std::cout << "z : " << z << std::endl;
            std::cout << "Statement5" << std::endl;
            std::cout << "Statement6" << std::endl;
            break;
    }
    std::cout << "Moving on..." << std::endl;

    return 0;
}