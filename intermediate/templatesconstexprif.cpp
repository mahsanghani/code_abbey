//
// Created by Ahsan Ghani on 2022-07-06.
//
#include <iostream>
#include <type_traits>
using namespace std;

void func_floating_point(double d)
{
    cout << "func_floating_point called..." << endl;
}

void func_integral(int i)
{
    cout << "func_integral called..." << endl;
}

template <typename T>
void func(T t)
{
    if constexpr(is_integral_v<T>)
    {
        func_integral(t);
    }
    else if constexpr(is_floating_point_v<T>)
    {
        func_floating_point(t);
    }
    else
    {
        static_assert(is_integral_v<T> || is_floating_point_v<T>,
                      "Argument must be integral of floating point");
    }
}

int main()
{
    func(12);

    return 0;
}