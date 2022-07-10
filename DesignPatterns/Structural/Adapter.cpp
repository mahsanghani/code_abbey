//
// Created by Ahsan Ghani on 2022-07-10.
//

// Adapter is a structural design pattern that
// allows objects with incompatible interfaces to collaborate.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Target
{
public:
    virtual ~Target() = default;
    virtual string Request() const
    {
        return "Target: the default target's behaviour.";
    }
};

class Adaptee {
public:
    string SpecificRequest() const
    {
        return ".eetpadA eht fo roivaheb laicepS";
    }
};

class Adapter: public Target
{
private:
    Adaptee *adaptee_;

public:
    Adapter(Adaptee *adaptee) : adaptee_(adaptee) {}
    string Request() const override
    {
        string to_reverse = this->adaptee_->SpecificRequest();
        reverse(to_reverse.begin(), to_reverse.end());
        return "Adapter: (TRANSLATED)" + to_reverse;
    }
};

void ClientCode(const Target *target)
{
    cout << target->Request() << endl;
}

int main()
{
    std::cout << "Client: I can work just fine with the Target objects:\n";
    Target *target = new Target;
    ClientCode(target);
    std::cout << "\n\n";
    Adaptee *adaptee = new Adaptee;
    std::cout << "Client: The Adaptee class has a weird interface. See, I don't understand it:\n";
    std::cout << "Adaptee: " << adaptee->SpecificRequest();
    std::cout << "\n\n";
    std::cout << "Client: But I can work with it via the Adapter:\n";
    Adapter *adapter = new Adapter(adaptee);
    ClientCode(adapter);
    std::cout << "\n";

    delete target;
    delete adaptee;
    delete adapter;

    return 0;
}