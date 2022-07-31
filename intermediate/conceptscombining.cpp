//
// Created by Ahsan Ghani on 2022-07-31.
//
#include <iostream>
#include <concepts>
using namespace std;

template <typename T>
concept TinyType = requires ( T t){
sizeof(T) <=4; // Simple requirement
requires sizeof(T) <= 4; // Nested requirement
};

template <typename T>
//requires std::integral<T> || std::floating_point<T> // OR operator
//requires std::integral<T> && TinyType<T>
requires std::integral<T> && requires ( T t){
sizeof(T) <=4; // Simple requirement
requires sizeof(T) <= 4; // Nested requirement
}

T add(T a, T b){
    return a + b;
}

int main(){
    int x{7};
    int y{5};
    cout << add(x,y) << endl;
    return 0;
}