//
// Created by Ahsan Ghani on 2022-10-31.
//
#ifndef VEHICLE_H
#define VEHICLE_H

#include "TrafficObject.h"

using namespace std;

class Street;
class Intersection;

class Vehicle : public TrafficObject,
                public std::enable_shared_from_this<Vehicle> {
public:
  Vehicle();

  void setCurrentStreet(std::shared_ptr<Street> street) {
    _currStreet = street;
  };
  void setCurrentDestination(std::shared_ptr<Intersection> destination);

  void simulate();

  std::shared_ptr<Vehicle> get_shared_this() { return shared_from_this(); }

private:
  void drive();

  std::shared_ptr<Street> _currStreet;
  std::shared_ptr<Intersection> _currDestination;
  double _posStreet;
  double _speed;
};
#endif