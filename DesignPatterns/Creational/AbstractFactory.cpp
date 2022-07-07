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

class ConcreteProductB1: public AbstractProductB {
public:
    string UsefulFunctionB() const override {
        return "The result of the product B1.";
    }
    string AnotherUsefulFunctionB(const AbstractProductA &collaborator) const override {
        const string result = collaborator.UsefulFunctionA();
        return "The result of the B1 collaborating with (" + result + ")";
    }
};

class ConcreteProductB2: public AbstractProductB {
public:
    string UsefulFunctionB() const override {
        return "The result of the product B2.";
    }
    string AnotherUsefulFunctionB(const AbstractProductA &collaborator) const override {
        const string result = collaborator.UsefulFunctionA();
        return "The result of the B1 collaborating with (" + result + ")";
    }
};

class AbstractFactory {
public:
    virtual AbstractProductA *CreateProductA() const = 0;
    virtual AbstractProductB *CreateProductB() const = 0;
};

class ConcreteFactory1: public AbstractFactory {
public:
    AbstractProductA *CreateProductA() const override {
        return new ConcreteProductA1();
    }
    AbstractProductB *CreateProductB() const override {
        return new ConcreteProductB1();
    }
};

class ConcreteFactory2: public AbstractFactory {
public:
    AbstractProductA *CreateProductA() const override {
        return new ConcreteProductA2();
    }
    AbstractProductB *CreateProductB() const override {
        return new ConcreteProductB2();
    }
};

void ClientCode(const AbstractFactory &factory) {
    const AbstractProductA *product_a = factory.CreateProductA();
    const AbstractProductB *product_b = factory.CreateProductB();
    cout << product_b->UsefulFunctionB() << "\n";
    cout << product_b->AnotherUsefulFunctionB(*product_a) << "\n";
    delete product_a;
    delete product_b;
}