//
// Created by Ahsan Ghani on 2022-07-06.
//
#include <iostream>
using namespace std;

template <typename T, typename P>
decltype(auto) func_add1(T a, P b)
{
    return a+b;
}

auto func_add2(auto a, auto b)
{
    return a+b;
}

int main()
{
    int a{7};
    double b{78.2};

    auto result1 = func_add1(a,b);
    cout << "result: " << result1 << endl;
    cout << "sizeof(result): " << sizeof(result1) << endl;

    auto result2 = func_add2(a,b);
    cout << "result: " << result2 << endl;
    cout << "sizeof(result): " << sizeof(result2) << endl;

    return 0;
}