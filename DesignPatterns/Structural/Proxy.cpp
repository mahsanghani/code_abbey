//
// Created by Ahsan Ghani on 2022-07-13.
//

// Proxy is a structural design pattern that
// provides an object that acts as a substitute
// for a real service object used by a client.
// A proxy receives client requests,
// does some work (access control, caching, etc.)
// and then passes the request to a service object.

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

