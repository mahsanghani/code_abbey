//
// Created by Ahsan Ghani on 2022-10-30.
//

#ifndef STREET_H
#define STREET_H

#include "TrafficObject.h"

using namespace std;

class Intersection;

class Street : public TrafficObject, public enable_shared_from_this<Street> {
public:
  Street();

  double getLength() { return _length; }
  void setInIntersection(shared_ptr<Intersection> in);
  void setOutIntersection(shared_ptry<Intersection> out);

  shared_ptr<Intersection> getOutIntersection() { return _interOut; }
  shared_ptr<Intersection> getInIntersection() { return _interIn; }

  shared_ptr<Street> get_shared_this() { return shared_from_this(); }

private:
  double _length;
  shared_ptr<Intersection> _interIn, _interOut;
};

#endif