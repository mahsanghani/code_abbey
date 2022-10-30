//
// Created by Ahsan Ghani on 2022-10-30.
//

#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include "TrafficObject.h"
#include <condition_variable>
#include <deque>
#include <mutex>

using namespace std;

class Vehicle;

enum class TrafficLightPhase { kRed = 0; kGreen = 1; };