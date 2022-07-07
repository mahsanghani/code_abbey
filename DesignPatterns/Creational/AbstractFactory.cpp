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

class ConcreteProductA1 : public AbstractProductA {
public:
    std::string UsefulFunctionA() const override {
        return "The result of the product A1.";
    }
};

class ConcreteProductA2 : public AbstractProductA {
    std::string UsefulFunctionA() const override {
        return "The result of the product A2.";
    }
};

class AbstractProductB {
public:
    virtual ~AbstractProductB(){};
    virtual std::string UsefulFunctionB() const = 0;
    virtual std::string AnotherUsefulFunctionB(const AbstractProductA &collaborator) const = 0;
};

class ConcreteProductB1 : public AbstractProductB {
public:
    std::string UsefulFunctionB() const override {
        return "The result of the product B1.";
    }
    std::string AnotherUsefulFunctionB(const AbstractProductA &collaborator) const override {
        const std::string result = collaborator.UsefulFunctionA();
        return "The result of the B1 collaborating with ( " + result + " )";
    }
};

class ConcreteProductB2 : public AbstractProductB {
public:
    std::string UsefulFunctionB() const override {
        return "The result of the product B2.";
    }
    std::string AnotherUsefulFunctionB(const AbstractProductA &collaborator) const override {
        const std::string result = collaborator.UsefulFunctionA();
        return "The result of the B2 collaborating with ( " + result + " )";
    }
};

class AbstractFactory {
public:
    virtual AbstractProductA *CreateProductA() const = 0;
    virtual AbstractProductB *CreateProductB() const = 0;
};

