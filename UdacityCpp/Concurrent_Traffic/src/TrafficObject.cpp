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

void TrafficObject::setPosition(double x, double y) {
  posX_ = x;
  posY_ = y;
}

void TrafficObject::getPosition(double &x, double &y) {
  x = posX_;
  y = posY_;
}

TrafficObject::TrafficObject() {
  type_ = ObjectType::noObject;
  id_ = id_cnt_++;
}

TrafficObject::~TrafficObject() {
  for_each(threads_.begin(), threads_.end(), [](thread &t) { t.join(); });
}
