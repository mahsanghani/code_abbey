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
    Node() {}
    Node(int idx, RouteMode *search_model, Model::Node node)
        : Model::Node(node), parent_model(search_model), index(idx) {}
    Node *parent = nullptr;
    float h_value = numeric_limits<float>::max();
    float g_value = 0;
    bool visited = false;
    vector<Node *> neighbors;

    float distance(Node) const;
    void FindNeighbors();

  private:
    int index;
    RouteModel *parent_model = nullptr;
    Node *FindNeighbor(vector<int>);
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