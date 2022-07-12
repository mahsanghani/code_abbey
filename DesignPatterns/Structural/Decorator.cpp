//
// Created by Ahsan Ghani on 2022-07-10.
//

// Decorator is a structural pattern that
// allows adding new behaviors to objects
// dynamically by placing them inside
// special wrapper objects, called decorators.

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Component
{
public:
    virtual ~Component() {}
    virtual string Operation() const = 0;
};

class ConcreteComponent : public Component
{
public:
    string Operation() const override
    {
        return "ConcreteComponent";
    }
};
