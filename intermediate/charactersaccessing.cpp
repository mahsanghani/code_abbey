//
// Created by Ahsan Ghani on 2022-07-01.
//
#include <iostream>
#include <string>

int main(){
    std::string str1 {"Hello there"};

    //Size of a string : doesn't count the null terminator
    std::cout << "str1.size() : " << str1.size() << std::endl;

    //Reading characters in std::string : array index operator
    //Regular indexed loop. Can also be adapted to use while and do-while
    //This is left as an exercise.
    std::cout << std::endl;
    std::cout << "For loop with array index notation : "<< std::endl;

    std::cout << "str1(for loop) : " ;
    for(size_t i{}; i < str1.size(); ++i){
        std::cout << " " << str1[i] ;
    }
    std::cout << std::endl;

    //Can also use range based for loop
    std::string str2 {"Hello there"};
    std::cout << std::endl;
    std::cout << "Using range based for loop : "<< std::endl;

    std::cout << "str1(range based for loop) : " ;
    for(char value : str2){
        std::cout << " " << value ;
    }
    std::cout << std::endl;

    //at() syntax to target characters
    std::cout << std::endl;
    std::cout << "Using the std::string::at() method : "<< std::endl;
    std::string str3 {"Hello there"};
    std::cout << "str1 : (for loop with at()) : " ;
    for(size_t i{}; i < str3.size(); ++i){
        std::cout << " " << str3.at(i) ;
    }
    std::cout << std::endl;

    //Modifying with operator[] and at()
    std::string str4 {"Hello there"};
    str4[0] = 'B';
    str4.at(1) = 'a';
    std::cout << "str1(modified) : " << str4 << std::endl;

    //Getting the front and back characters
    std::string str5{"The Phoenix King"};
    char& front_char = str5.front();
    char& back_char = str5.back();
    std::cout << "The front char in str5 is : " << front_char << std::endl;
    std::cout << "The back char in str5 is : " << back_char << std::endl;
    front_char = 'r';
    back_char = 'd';
    std::cout << "str5 : " << str5 << std::endl;

    //c_str method
    //doc : https://en.cppreference.com/w/cpp/string/basic_string/c_str
    //returns const char * to the wrapped string. You shouldn't use
    //it to modify data in the string.
    std::string str6{"The Phoenix King"};
    const char * wrapped_c_string = str6.c_str();
    std::cout << "Wrapped c string : " << wrapped_c_string << std::endl;
    //wrapped_c_string[0] = 'e'; // Compiler error

    //data()
    std::string str7 { "Hello World"};

    char * data = str7.data();
    std::cout << "Wrapped c string : " << data << std::endl;
    data[0] = 'B';// This also changes std::string.

    std::cout << "Wrapped c string (after modification) : " << data << std::endl;
    std::cout << "Original string (after modification ) :" << str7 << std::endl;
    return 0;
}