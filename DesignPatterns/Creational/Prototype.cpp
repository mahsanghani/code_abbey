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
