//
// Created by Ahsan Ghani on 2022-07-06.
//
#include <iostream>
using namespace std;

template <typename ReturnType = double, typename T, typename P>
ReturnType maximum (T a, P b)
{
    return (a>b) ? a : b;
}

template <typename T, typename P, typename ReturnType = double>
ReturnType minimum (T a, P b)
{
    return (a<b) ? a : b;
}

int main()
{
    double a{6};
    double b{9.5};

    auto result = minimum<int,double,int> (a,b);
    cout << "result: " << result << endl;
    cout << "sizeof(result): " << sizeof(result) << endl;

    return 0;
}