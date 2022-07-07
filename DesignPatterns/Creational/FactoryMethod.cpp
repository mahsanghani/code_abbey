//
// Created by Ahsan Ghani on 2022-07-07.
//

// Factory Method is a creational design pattern that
// provides an interface for creating objects in a superclass,
// but allows subclasses to alter the type of objects that will be created.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Product {
public:
    virtual ~Product() {}
    virtual string Operation() const = 0;
};

class ConcreteProduct1 : public Product {
public:
    string Operation() const override {
        return "{Result of the ConcreteProduct1}";
    }
};

class ConcreteProduct2 : public Product {
public:
    string Operation() const override {
        return "{Result of the ConcreteProduct2}";
    }
};

class Creator {
public:
    virtual ~Creator(){};
    virtual Product* FactoryMethod() const = 0;
    string SomeOperation() const {
        Product* product = this->FactoryMethod();
        string result = "Creator: The same creator's code has just worked with " + product->Operation();
        delete product;
        return result;
    }
};

class ConcreteCreator1 : public Creator {
public:
    Product* FactoryMethod() const override {
        return new ConcreteProduct1();
    }
};

class ConcreteCreator2 : public Creator {
public:
    Product* FactoryMethod() const override {
        return new ConcreteProduct2();
    }
};