//
// Created by Ahsan Ghani on 2022-10-31.
//
#ifndef TRAFFICOBJECT_H
#define TRAFFICOBJECT_H

#include <mutex>
#include <thread>
#include <vector>

using namespace std;

enum ObjectType {
  noObject,
  objectVehicle,
  objectIntersection,
  objectStreet,
};