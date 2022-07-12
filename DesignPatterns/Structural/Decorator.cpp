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

class Decorator : public Component
{
protected:
    Component* component_;
public:
    Decorator(Component* component) : component_(component) {}
    string Operation() const override
    {
        return this->component_->Operation();
    }
};

class ConcreteDecoratorA : public Decorator
{
public:
    ConcreteDecoratorA(Component* component) : Decorator(component) {}
    string Operation() const override
    {
        return "ConcreteDecoratorA(" + Decorator::Operation() + ")";
    }
};

class ConcreteDecoratorB : public Decorator
{
public:
    ConcreteDecoratorB(Component* component) : Decorator(component) {}
    string Operation() const override
    {
        return "ConcreteDecoratorB(" + Decorator::Operation() + ")";
    }
};

void ClientCode(Component* component)
{
    cout << "RESULT: " << component->Operation() << endl;
}

int main()
{
    Component* simple = new ConcreteComponent;
    cout << "Client: I've got a simple component." << endl;
    ClientCode(simple);
    cout << "\n" << endl;

    Component* decorator1 = new ConcreteDecoratorA(simple);
    Component* decorator2 = new ConcreteDecoratorB(decorator1);
    cout << "Client: Now I've got a decorated component." << endl;

    ClientCode(decorator2);
    cout << "\n" << endl;

    delete simple;
    delete decorator1;
    delete decorator2;
    return 0;
}