//
// Created by Ahsan Ghani on 2022-07-06.
//
#include <iostream>
#include <type_traits>
using namespace std;

template <typename T>
void print_number( T n){
    static_assert(is_integral_v<T> ,"print_number() can only be called with integral types" );
    cout << "number : " << n << endl;
}


int main()
{
    cout << boolalpha;
    cout << "std::is_integral<int> : " << is_integral<int>::value << endl;
    cout << "std::is_floating_point<int> : " << is_floating_point<int>::value << endl;
    cout << "-------------" << endl;
    cout << "std::is_integral_v<int> : " << is_integral_v<int> << endl;
    cout << "std::is_floating_point_v<int> : " << is_floating_point_v<int> << endl;

    double a{7};
    print_number(a);

    auto func = []<typename T>(T a, T b){
        static_assert(is_integral_v<T>,"func can only be called with integral types");
        return a + b;
    };

    double x {7};
    double y{6};
    func(x,y);

    return 0;
}