//
// Created by Ahsan Ghani on 2022-07-13.
//

// Flyweight is a structural design pattern that
// lets you fit more objects into the available
// amount of RAM by sharing common parts of state
// between multiple objects instead of keeping all data.

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

struct SharedState
{
    string brand_;
    string model_;
    string colour_;

    SharedState(
            const string &brand,
            const string &model,
            const string &colour
            ) : brand_(brand),
            model_(model),
            colour_(colour) {}

    friend ostream &operator<<(ostream &os, const SharedState &ss)
    {
        return os << "[ " << ss.brand_ << " , " << ss.model_ << " , " << ss.colour_ << " ]";
    }
};

struct UniqueState
{
    string owner_;
    string plates_;

    UniqueState(
            const string &owner,
            const string &plates
            ) : owner_(owner),
            plates_(plates) {}

    friend ostream &operator<<(ostream &os, const UniqueState &us)
    {
        return os << "[ " << us.owner_ << " , " << us.plates_ << " ]";
    }
};

class Flyweight
{
private:
    SharedState *shared_state_;
public:
    Flyweight(const SharedState *shared_state) : shared_state_(new SharedState(*shared_state)) {}
    Flyweight(const Flyweight &other) : shared_state_(new SharedState(*other.shared_state_)) {}
    ~Flyweight()
    {
        delete shared_state_;
    }
    SharedState *shared_state() const
    {
        return shared_state_;
    }
    void Operation(const UniqueState &unique_state) const
    {
        cout << "Flyweight: Displaying shared (" << *shared_state_ << ") and unique (" << unique_state << ") state.\n";
    }
};