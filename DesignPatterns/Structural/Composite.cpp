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

class Componennt
{
protected:
    Componennt *parent_;

public:
    virtual ~Componennt() {}
    void SetParent(Componennt *parent)
    {
        this->parent_ = parent;
    }
    Componennt *GetParent() const
    {
        return this->parent_;
    }

    virtual void Add(Componennt *component) {}
    virtual void Remove(Componennt *componennt) {}
    virtual bool IsComposite() const
    {
        return false;
    }
    virtual string Operation() const = 0;
};