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
    string OperationN() const
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
    string OperationZ() const
    {
        return "Subsystem2: Fire!\n";
    }
};

class Facade
{
protected:
    Subsystem1 *subsystem1_;
    Subsystem2 *subsystem2_;
public:
    Facade(Subsystem1 *subsystem1 = nullptr,
            Subsystem2 *subsystem2 = nullptr)
    {
        this->subsystem1_ = subsystem1 ?: new Subsystem1;
        this->subsystem2_ = subsystem2 ?: new Subsystem2;
    }
    ~Facade()
    {
        delete subsystem1_;
        delete subsystem2_;
    }
    string Operation()
    {
        string result = "Facade initializes subsystem:\n";
        result += this->subsystem1_->Operation1();
        result += this->subsystem2_->Operation1();
        result += "Facade orders subsystems to perform the action:\n";
        result += this->subsystem1_->OperationN();
        result += this->subsystem2_->OperationZ();
        return result;
    }
};