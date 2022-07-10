//
// Created by Ahsan Ghani on 2022-07-10.
//

// Composite is a structural design pattern that
// allows composing objects into a tree-like structure
// and work with it as if it was a singular object.

#include <algorithm>
#include <iostream>
#include <list>
#include <string>
using namespace std;

class Component
{
protected:
    Component *parent_;

public:
    virtual ~Component() {}
    void SetParent(Component *parent)
    {
        this->parent_ = parent;
    }
    Component *GetParent() const
    {
        return this->parent_;
    }

    virtual void Add(Component *component) {}
    virtual void Remove(Component *componennt) {}
    virtual bool IsComposite() const
    {
        return false;
    }
    virtual string Operation() const = 0;
};

class Leaf: public Component
{
public:
    string Operation() const override
    {
        return "Leaf";
    }
};

class Composite : public Component
{
protected:
    list<Component *> children_;

public:
    void Add(Component *component) override
    {
        this->children_.push_back(component);
        component->SetParent(this);
    }
    void Remove(Component *component) override
    {
        children_.remove(component);
        component->SetParent(nullptr);
    }
    bool IsComposite() const override
    {
        return true;
    }
    string Operation() const override
    {
        string result;
        for (const Component *c : children_)
        {
            if (c == children_.back())
            {
                result += c->Operation();
            }
            else
            {
                result += c->Operation() + "+";
            }
        }
        return "Branch(" + result + ")";
    }
};