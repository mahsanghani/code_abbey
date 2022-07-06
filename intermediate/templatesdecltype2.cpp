//
// Created by Ahsan Ghani on 2022-07-06.
//
#include <iostream>
#include <type_traits>
using namespace std;

struct A {double x;};
const A* a;

decltype(a->x) y;
decltype((a->x)) z = y;

template<typename T, typename U>
auto add(T t, U u) -> decltype(t+u)
{
    return t+u;
}

const int& getRef(const int* p) { return *p; }
static_assert(std::is_same_v<decltype(getRef), const int&(const int*)>);

auto getRefFwdBad(const int* p) { return getRef(p); }
static_assert(std::is_same_v<decltype(getRefFwdBad), int(const int*)>,
              "Just returning auto isn't perfect forwarding.");

decltype(auto) getRefFwdGood(const int* p) { return getRef(p); }
static_assert(std::is_same_v<decltype(getRefFwdGood), const int&(const int*)>,
              "Returning decltype(auto) perfectly forwards the return type.");

auto getRefFwdGood1(const int* p) -> decltype(getRef(p)) { return getRef(p); }
static_assert(std::is_same_v<decltype(getRefFwdGood1), const int&(const int*)>,
              "Returning decltype(return expression) also perfectly forwards the return type.");

int main()
{
    int i = 33;
    decltype(i) j = i * 2;
    cout << "i and j are the same type?" << boolalpha
         << is_same_v<decltype(i), decltype(j)> << '\n';

    cout << "i = " << i << ", j = " << j << '\n';

    auto f = [](int a, int b) -> int
    {
        return a*b;
    };

    decltype(f) g = f;
    i = f(2,2);
    j = g(3,3);

    cout << "i = " << i << ", j = " << j << '\n';
}