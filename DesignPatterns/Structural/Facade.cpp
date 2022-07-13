//
// Created by Ahsan Ghani on 2022-07-11.
//

// Facade is a structural design pattern that
// provides a simplified (but limited) interface
// to a complex system of classes, library or framework.

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Subsystem1
{
public:
    string Operation1() const
    {
        return "Subsystem1: Ready!\n";
    }
    string Operation2() const
    {
        return "Subsystem1: Go!\n"
    }
};

class Subsystem2
{
public:
    string Operation1() const
    {
        return "Subsystem2: Get Ready!\n";
    }
    string Operation2() const
    {
        return "Subsystem2: Fire!\n";
    }
};

