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

void ClientCode(Component *component)
{
    cout << "RESULT: " << component->Operation() << endl;
}

void ClientCode2(Component *component1, Component *component2)
{
    if (component1->IsComposite())
    {
        component1->Add(component2);
    }
    cout << "RESULT: " << component1->Operation() << endl;
}

int main()
{
    Component *simple = new Leaf;
    cout << "Client: I've got a simple component:\n" << endl;
    ClientCode(simple);
    cout << "\n" << endl;

    Component *tree = new Composite;
    Component *branch1 = new Composite;
    Component *branch2= new Composite;

    Component *leaf_1 = new Leaf;
    Component *leaf_2 = new Leaf;
    Component *leaf_3 = new Leaf;

    branch1->Add(leaf_1);
    branch1->Add(leaf_2);
    branch2->Add(leaf_3);

    tree->Add(branch1);
    tree->Add(branch2);

    cout << "Client: Now I've got a composite tree:\n";
    ClientCode(tree);
    cout << "\n" << endl;
    cout << "Client: I don't need ot check the components classes even when managing the tree:\n";
    ClientCode2(tree,simple);
    cout << "\n" << endl;

    delete simple;
    delete tree;
    delete branch1;
    delete branch2;
    delete leaf_1;
    delete leaf_2;
    delete leaf_3;
    return 0;
}
