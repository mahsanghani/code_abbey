//
// Created by Ahsan Ghani on 2022-07-31.
//
#include <iostream>
#include <concepts>
using namespace std;

template <typename T>
concept TinyType = requires (T t){
sizeof(T) <= 4; // Simple requirement : Only enforces syntax
requires sizeof(T) <= 4; // Nested requirements
};

//Compound requirement
template <typename T>
concept Addable = requires (T a, T b) {
//noexcept is optional
{a + b} -> convertible_to<int>; //Compound requirement
//Checks if a + b is valid syntax, doesn't throw expetions(optional) , and the result
//is convertible to int(optional)
};

Addable auto add( Addable auto a, Addable auto b){
    return a + b;
}

int main(){

    double x{67};
    double y{56};

    //string x{"Hello"};
    //string y{"World"};
    //auto s = x + y;

    auto result  = add(x,y);
    cout << "result : " << result << endl;
    cout << "sizeof(result) : " << sizeof(result) << endl;

    return 0;
}