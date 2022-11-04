//
// Created by Ahsan Ghani on 2022-11-03.
//
#pragma once

#include <cstddef>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Model {
public:
  struct Node {
    double x = 0.f;
    double y = 0.f;
  };

  struct Way {
    vector<int> nodes;
  };

  struct Road {
    enum Type {
      Invalid,
      Unclassified,
      Service,
      Residential,
      Tertiary,
      Secondary,
      Primary,
      Trunk,
      Motorway,
      Footway
    };
    int way;
    Type type;
  };

  struct Railway {
    int way;
  };

  struct Multipolygon {
    vector<int> outer;
    vector<int> inner;
  };

  struct Building : Multipolygon {};

  struct Leisure : Multipolygon {};

  struct Water : Multipolygon {};

  struct Landuse : Multipolygon {
    enum Type {
      Invalid,
      Commercial,
      Construction,
      Grass,
      Forest,
      Industrial,
      Railway,
      Residential
    };
    Type type;
  };

  Model(const std::vector<std::byte> &xml);
}