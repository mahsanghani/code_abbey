//
// Created by Ahsan Ghani on 2022-07-06.
//
#include <iostream>
using namespace std;

template <typename T, typename P>
decltype(auto) maximum(T a, P b)
{
    return (a > b) ? a : b;
}

int main()
{
    int x{7};
    double y{5.9};

    auto result = maximum(x,y);
    cout << "max: " << result << endl;
    cout << "sizeof(result): " << sizeof(result) << endl;

    return 0;
}