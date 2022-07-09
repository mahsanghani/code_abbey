//
// Created by Ahsan Ghani on 2022-07-09.
//
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include <unordered_map>
using namespace std;

class Singleton {
protected:
    Singleton(const string value): value_(value) {}

    static Singleton* singleton_;
    string value_;

public:
    Singleton(Singleton &other) = delete;
    void operator = (const Singleton &) = delete;

    static Singleton *GetInstance(const string value);
    void SomeBusinessLogic() {}
    string value() const
    {
        return value_;
    }
};