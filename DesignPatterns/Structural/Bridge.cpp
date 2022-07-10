//
// Created by Ahsan Ghani on 2022-07-10.
//


// Bridge is a structural design pattern that
// divides business logic or huge class into separate
// class hierarchies that can be developed independently.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Implementation
{
public:
    virtual ~Implementation() {}
    virtual string OperationImplementation() const = 0;
};

class ConcreteImplementationA : public Implementation
{
    string OperationImplementation() const override
    {
        return "ConcreteImplementationA: Here's the result on the platform A.\n";
    }
};

class ConcreteImplementationB : public Implementation
{
    string OperationImplementation() const override
    {
        return "ConcreteImplementationA: Here's the result on the platform B.\n";
    }
};
