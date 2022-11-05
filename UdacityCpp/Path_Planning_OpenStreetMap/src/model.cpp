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

void Model::LoadData(const vector<byte> &xml) {
  using namespace pugi;

  xml_document doc;
  if (!doc.load_buffer(xml.data(), xml.size())) {
    throw logic_error("failed to parse the xml file");
  }

  if (auto bounds = doc.select_nodes("/osm/bounds"); !bounds.empty()) {
    auto node = bounds.first().node();
    m_MinLat = atof(node.attribute("minlat").as_string());
    m_MaxLat = atof(node.attribute("maxlat").as_string());
    m_MinLon = atof(node.attribute("minlon").as_string());
    m_MaxLon = atof(node.attribute("maxlon").as_string());
  } else {
    throw logic_error("map's bounds are not defined");
  }

  unordered_map<string, int> node_id_to_num;
  for (const auto &node : doc.select_nodes("/osm/node")) {
    node_id_to_num[node.node().attribute("id").as_string()] =
        (int)m_Nodes.size();
    m_Nodes.emplace_back();
    m_Nodes.back().y = atof(node.node().attribute("lat").as_string());
    m_Nodes.back().x = atof(node.node().attribute("lon").as_string());
  }
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

static bool TrackRec(const vector<int> &open_ways, const Model::Way *ways,
                     vector<bool> &used, vector<int> &nodes) {
  if (nodes.empty()) {
    for (int i = 0; i < open_ways.size(); ++i) {
      if (!used[i]) {
        used[i] = true;
        const auto &way_nodes = ways[open_ways[i]].nodes;
        nodes = way_nodes;
        if (TrackRec(open_ways, ways, used, nodes)) {
          return true;
        }
        nodes.clear();
        used[i] = false;
      }
    }
    return false;
  } else {
    const auto head = nodes.front();
    const auto tail = nodes.back();
    if (head == tail && nodes.size() > 1) {
      return true;
    }
    for (int i = 0; i < open_ways.size(); ++i) {
      if (!used[i]) {
        const auto &way_nodes = ways[open_ways[i]].nodes;
        const auto way_head = way_nodes.front();
        const auto way_tail = way_nodes.back();
        if (way_head == tail || way_tail == tail) {
          used[i] = true;
          const auto len = nodes.size();
          if (way_head == tail) {
            nodes.insert(nodes.end(), way_nodes.begin(), way_nodes.end());
          } else {
            nodes.insert(nodes.end(), way_nodes.begin(), way_nodes.rend());
          }
          if (TrackRec(open_ways, ways, used, nodes)) {
            return true;
          }
          nodes.resize(len);
          used[i] = false;
        }
      }
      return false;
    }
  }
}

static vector<int> Track(vector<int> &open_ways, const Model::Way *ways) {
  assert(!open_ways.empty());
  vector<bool> used(open_ways.size(), false);
  vector<int> nodes;
  if (TrackRec(open_ways, ways, used, nodes)) {
    for (int i = 0; i < open_ways.size(); ++i) {
      if (used[i]) {
        open_ways[i] = -1;
      }
    }
  }
  return nodes;
}

void Model::BuildRings(Multipolygon &mp) {
  auto is_closed = [](const Model::Way &way) {
    return way.nodes.size() > 1 && way.nodes.front() == way.nodes.back();
  };

  auto process = [&](vector<int> &ways_nums) {
    auto ways = m_Ways.data();
    vector<int> closed, open;

    for (auto &way_num : ways_nums) {
      (is_closed(ways[way_num]) ? closed : open).emplace_back(way_num);
    }

    while (!open.empty()) {
      auto new_nodes = Track(open, ways);
      if (new_nodes.empty()) {
        break;
      }
      open.erase(
          remove_if(open.begin(), open.end(), [](auto v) { return v < 0; }),
          open.end());
      closed.emplace_back((int)m_Ways.size());
      Model::Way new_way;
      new_way.nodes = move(new_nodes);
      m_Ways.emplace_back(new_way);
    }
    swap(ways_nums, closed);
  };
  process(mp.outer);
  process(mp.inner);
}