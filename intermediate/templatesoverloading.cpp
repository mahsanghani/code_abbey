//
// Created by Ahsan Ghani on 2022-07-04.
//
#include <iostream>
#include <string>
using namespace std;

template <typename T>
T maximum(T a, T b){
    cout << "Template overload called (T) " << endl;
    return (a > b) ? a : b;
}

template <>
const char * maximum<const char*> (const char* a, const char* b){
    cout << "Raw overload called" << endl;
    return (strcmp(a,b) > 0) ? a : b;
}

template <typename T> T* maximum(T* a, T* b){
    cout << "Template overload called (T*) " << endl;
    return (*a > *b) ? a : b;
}

int main(){
    const char* g{"wild"};
    const char* h{"animal"};
    const char* result = maximum(g,h);

    int a{810};
    int b{23};
    auto result2 = maximum(&a,&b);
    cout << "result2: " << *result2 << endl;
    return 0;
}