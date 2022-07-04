//
// Created by Ahsan Ghani on 2022-07-04.
//
#include <iostream>
#include <string>
using namespace std;

template <typename T>
T maximum(T a, T b){
    return (a > b) ? a : b;
}

template <>
const char * maximum<const char*> (const char* a, const char* b){
    return (strcmp(a,b) > 0) ? a : b;
}

int main(){
    int a{10};
    int b{23};
    double c{34.7};
    double d{23.4};
    string e{"hello"};
    string f{"world"};

    auto max_int = maximum(a,b);
    auto max_double = maximum(c,d);
    auto max_str = maximum(e,f);

    cout << "max_int: " << max_int << endl;
    cout << "max_double: " << max_double << endl;
    cout << "max_str: " << max_str << endl;

    const char* g{"wild"};
    const char* h{"animal"};

    const char* result = maximum(g,h);
    cout << "max(const char*): " << result << endl;

    return 0;
}