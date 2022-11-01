//
// Created by Ahsan Ghani on 2022-10-31.
//
#include "TrafficObject.h"
#include <algorithm>
#include <chrono>
#include <iostream>

using namespace std;

int TrafficObject::id_cnt_ = 0;

mutex TrafficObject::mtx_;
