//
// Created by Ahsan Ghani on 2022-07-08.
//
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

enum Type
{
    PROTOTYPE_1 = 0;
    PROTOTYPE_2;
};

class Prototype {
protected:
    string prototype_name_;
    float prototype_field_;

public:
    Prototype() {}
    Prototype(string prototype_name)
    : prototype_name_(prototype_name) {}
    virtual ~Prototype() {}
    virtual Prototype *Clone() const = 0;
    virtual void Method(float prototype_field)
    {
        this->prototype_field_ = prototype_field;
        cout << "Call Method from " << prototype_name_
        << " with field: " << prototype_field << endl;
    }
};

class ConcretePrototype1 : public Prototype {
private:
    float concrete_prototype_field1_;

public:
    ConcretePrototype1(string prototype_name, float concrete_prototype_field)
    : Prototype(prototype_name), concrete_prototype_field1_(concrete_prototype_field) {}
    Prototype *Clone() const override
    {
        return new ConcretePrototype1(*this);
    }
};

class ConcretePrototype2 : public Prototype {
private:
    float concrete_prototype_field1_;

public:
    ConcretePrototype2(string prototype_name, float concrete_prototype_field)
            : Prototype(prototype_name), concrete_prototype_field1_(concrete_prototype_field) {}
    Prototype *Clone() const override
    {
        return new ConcretePrototype2(*this);
    }
};