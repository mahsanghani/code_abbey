//
// Created by Ahsan Ghani on 2022-11-03.
//
#pragma once

#include "route_model.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class RoutePlanner {
public:
  RoutePlanner(RoutePlanner &model, float start_x, float start_y, float end_x,
               float end_y);
  float GetDistance() { return distance; }
  void AStarSearch();
};