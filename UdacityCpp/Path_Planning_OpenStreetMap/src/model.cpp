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

static Model::Landuse::Type String2LanduseType(std::string_view type) {
  if (type == "commercial")
    return Model::Landuse::Commercial;
  if (type == "construction")
    return Model::Landuse::Construction;
  if (type == "grass")
    return Model::Landuse::Grass;
  if (type == "forest")
    return Model::Landuse::Forest;
  if (type == "industrial")
    return Model::Landuse::Industrial;
  if (type == "railway")
    return Model::Landuse::Railway;
  if (type == "residential")
    return Model::Landuse::Residential;
  return Model::Landuse::Invalid;
}

Model::Model(const std::vector<std::byte> &xml) {
  LoadData(xml);

  AdjustCoordinates();

  std::sort(m_Roads.begin(), m_Roads.end(),
            [](const auto &_1st, const auto &_2nd) {
              return (int)_1st.type < (int)_2nd.type;
            });
}
