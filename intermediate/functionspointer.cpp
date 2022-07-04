//
// Created by Ahsan Ghani on 2022-07-03.
//
#include <iostream>

int* max_return_pointer(int* a, int* b)
{
    if(*a > *b) {
        return a;
    } else {
        return b;
    }
}

int* max_input_by_value (int a, int b)
{
    if(a > b) {
        return &a; // Pointer to local variable returned
    } else {
        return &b; // Pointer to local variable returned
    }
}


int* sum( int* a, int* b){
    int result = *a + *b;
    return &result;// Pointer to local variable returned
}


int main(){
    int x{56};
    int y{45};
    int* p_max = max_return_pointer(&x,&y);
    std::cout << "x : " << x << std::endl;
    std::cout << "y : " << y << std::endl;
    std::cout << "*p_max : " << *p_max << std::endl;
    ++(*p_max);
    std::cout << "-----" << std::endl;
    std::cout << "x : " << x << std::endl;
    std::cout << "y : " << y << std::endl;
    std::cout << "*p_max : " << *p_max << std::endl;
    int j{56};
    int k{45};
    int* p_sum = sum(&j,&k);
    std::cout << *p_sum << std::endl;
    int m{56};
    int n{45};
    int* p_sum2 = max_input_by_value(m,n);
    std::cout << *p_sum2 << std::endl;
    std::cout << "Done!" << std::endl;
    return 0;
}