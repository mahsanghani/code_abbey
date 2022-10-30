//
// Created by Ahsan Ghani on 2022-10-30.
//
#include "Street.h"
#include "Intersection.h"
#include "Vehicle.h"
#include <iostream>

using namespace std;

Street::Street() {
  type_ = ObjectType::objectStreet;
  _length = 1000.0;
}

void Street::setInIntersection(shared_ptr<Intersection> in) {
  _interIn = in;
  in->addStreet(get_shared_this());
}