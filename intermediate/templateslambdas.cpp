//
// Created by Ahsan Ghani on 2022-07-06.
//
#include <iostream>
using namespace std;

int main()
{
    auto func = []<typename T, typename P>(T a, P b)
    {
        return a+b;
    };

    char a{'c'};
    int b{63};

    auto result = func(a,b);
    cout << "result: " << result << endl;
    cout << "sizeof(result): " << sizeof(result) << endl;

    return 0;
}