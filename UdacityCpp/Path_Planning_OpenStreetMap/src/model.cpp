//
// Created by Ahsan Ghani on 2022-11-03.
//
#include "model.h"
#include "pugixml.hpp"
#include <algorithm>
#include <assert.h>
#include <cmath>
#include <iostream>
#include <string_view>

using namespace std;

static Model::Road::Type String2RoadType(std::string_view type) {
  if (type == "motorway")
    return Model::Road::Motorway;
  if (type == "trunk")
    return Model::Road::Trunk;
  if (type == "primary")
    return Model::Road::Primary;
  if (type == "secondary")
    return Model::Road::Secondary;
  if (type == "tertiary")
    return Model::Road::Tertiary;
  if (type == "residential")
    return Model::Road::Residential;
  if (type == "living_street")
    return Model::Road::Residential;
  if (type == "service")
    return Model::Road::Service;
  if (type == "unclassified")
    return Model::Road::Unclassified;
  if (type == "footway")
    return Model::Road::Footway;
  if (type == "bridleway")
    return Model::Road::Footway;
  if (type == "steps")
    return Model::Road::Footway;
  if (type == "path")
    return Model::Road::Footway;
  if (type == "pedestrian")
    return Model::Road::Footway;
  return Model::Road::Invalid;
}
