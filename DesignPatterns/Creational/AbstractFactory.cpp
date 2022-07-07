//
// Created by Ahsan Ghani on 2022-07-06.
//

// Abstract Factory is a creational design pattern
// that lets you produce families of related objects
// without specifying their concrete classes.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class AbstractProductA {
public:
    virtual ~AbstractProductA(){};
    virtual string UsefulFunctionA() const = 0;
};