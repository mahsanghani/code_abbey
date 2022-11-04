//
// Created by Ahsan Ghani on 2022-11-03.
//
#pragma once

#include "route_model.h"
#include <io2d.h>
#include <unordered_map>

using namespace std::experimental;

class Render {
public:
  Render(RouteModel &model);
  void Display(io2d::output_surface &surface);
};