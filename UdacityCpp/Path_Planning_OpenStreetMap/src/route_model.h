//
// Created by Ahsan Ghani on 2022-11-03.
//
#pragma once

#include "model.h"
#include <cmath>
#include <iostream>
#include <limits>
#include <unordered_map>

using namespace std;

class RouteModel : public Model {
public:
  class Node : public Model::Node {
  public:
  };

  RouteModel(const vector<byte> &xml);
  vector<Node> path;
  vector<Node> &SNodes() { return m_Nodes; }
  unordered_map<int, vector<const Model::Road *>> &GetNodeToRoadMap() {
    return node_to_road;
  }
  RouteModel::Node &FindClosestNode(float, float);

private:
  vector<Node> m_Nodes;
  unordered_map<int, vector<const Model::Road *>> node_to_road;

  void CreateNodeToRoadHashmap();
}