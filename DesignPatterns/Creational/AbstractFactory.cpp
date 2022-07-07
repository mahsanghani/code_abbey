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

class ConcreteProductA1: public AbstractProductA {
public:
    string UsefulFunctionA() const override
    {
        return "The result of the product A1.";
    }
};

class ConcreteProductA2: public AbstractProductA {
public:
    string UsefulFunctionA() const override
    {
        return "The result of the product A2.";
    }
};

class AbstractProductB {
public:
    virtual ~AbstractProductB(){};
    virtual string UsefulFunctionB() const = 0;
    virtual string AnotherUsefulFunctionB(const AbstractProductA &collaborator) const = 0;
};

