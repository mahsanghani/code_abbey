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