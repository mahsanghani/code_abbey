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

