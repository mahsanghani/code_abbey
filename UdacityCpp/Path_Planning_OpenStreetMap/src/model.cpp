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

void Model::AdjustCoordinates() {
  const auto pi = 3.14159265358979323846264338327950288;
  const auto deg_to_rad = 2. * pi / 360.;
  const auto earth_radius = 6378137.;
  const auto lat2ym = [&](double lat) {
    return log(tan(lat * deg_to_rad / 2 + pi / 4)) / 2 * earth_radius;
  };
  const auto lon2xm = [&](double lon) {
    return lon * deg_to_rad / 2 * earth_radius;
  };
  const auto dx = lon2xm(m_MaxLon) - lon2xm(m_MinLon);
  const auto dy = lat2ym(m_MaxLat) - lat2ym(m_MinLat);
  const auto min_y = lat2ym(m_MinLat);
  const auto min_x = lon2xm(m_MinLon);
  m_MetricScale = std::min(dx, dy);
  for (auto &node : m_Nodes) {
    node.x = (lon2xm(node.x) - min_x) / m_MetricScale;
    node.y = (lat2ym(node.y) - min_y) / m_MetricScale;
  }
}