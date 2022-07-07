//
// Created by Ahsan Ghani on 2022-07-06.
//
#include <iostream>
using namespace std;

class AbstractProductA {
public:
    virtual ~AbstractProductA(){};
    virtual std::string UsefulFunctionA() const = 0;
};