//
// Created by Ahsan Ghani on 2020-09-14.
//

// istream::get example
#include <iostream>     // std::cin, std::cout
#include <fstream>      // std::ifstream

int main () {
    char str[256];

    std::cout << "Enter the name of an existing text file: ";
    std::cin.get (str,256);    // get c-string

    std::ifstream is(str);     // open file

    char c;
    while (is.get(c))          // loop getting single characters
        std::cout << c;

    is.close();                // close file

    return 0;
}