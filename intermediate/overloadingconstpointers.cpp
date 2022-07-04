//
// Created by Ahsan Ghani on 2022-07-04.
//
#include <iostream>

int max(int*a , int* b){
    std::cout << "max with int* called" << std::endl;
    return (*a > *b)? *a : *b;
}

int max(const int* a, const int* b){
    std::cout << "max with cont int* called" << std::endl;
    return (*a > *b)? *a : *b;
}

/*
int min(const int* a, const int* b){
    return (*a < *b)? *a : *b;
}
*/

int min(const int* const a, const int* const b){
    std::cout << "&a : " << &a << std::endl;
    std::cout << "&b : " << &b << std::endl;
    return (*a < *b)? *a : *b;
}

int main(){
    int a{10};
    int b{12};
    const int c{30};
    const int d{15};
    auto result = max(&c,&c);

    const int e{30};
    const int f{15};

    const int* p_e{&e};
    const int* p_f{&f};

    std::cout << "&p_e : " << &p_e << std::endl;
    std::cout << "&p_f : " << &p_f << std::endl;

    auto result2 = min(p_e,p_f);
    return 0;
}