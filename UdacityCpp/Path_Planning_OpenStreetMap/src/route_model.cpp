//
// Created by Ahsan Ghani on 2022-11-03.
//
#include "route_model.h"
#include <iostream>

using namespace std;

RouteModel::RouteModel(const vector<byte> &xml) : Model(xml) {
  int counter = 0;
  for (auto node : this->Nodes()) {
    m_Nodes.push_back(Node(counter, this, node));
    counter++;
  }
  CreateNodeToRoadHashmap();
}

float RouteModel::Node::distance(RouteModel::Node anotherNode) const {
  return sqrt(pow(this->x - anotherNode.x, 2) +
              pow(this->y - anotherNode.y, 2));
}

void RouteModel::CreateNodeToRoadHashmap() {
  for (const Model::Road &road : Roads()) {
    if (road.type != Model::Road::Type::Footway) {
      for (auto node_idx : Ways()[road.way].nodes) {
        if (node_to_road.find(node_idx) == node_to_road.end()) {
          node_to_road[node_idx] = vector<const Model::Road *>{};
        }
        node_to_road[node_idx].push_back(&road);
      }
    }
  }
}

RouteModel::Node *RouteModel::Node::FindNeighbor(vector<int> node_indices) {
  Node *closest_node = nullptr;

  for (int node_index : node_indices) {
    RouteModel::Node &evalNode = parent_model->SNodes()[node_index];

    if (!evalNode.visited && this->distance(evalNode) > 0) {
      if (!closest_node) {
        closest_node = &evalNode;
      } else {
        if (this->distance(*closest_node) > this->distance(evalNode))
          closest_node = &evalNode;
      }
    }
  }
  return closest_node;
}

void RouteModel::Node::FindNeighbors() {
  for (const Model::Road *&road : parent_model->node_to_road[this->index]) {
    RouteModel::Node *node_ptr =
        FindNeighbor(parent_model->Ways()[road->way].nodes);
    if (node_ptr) {
      this->neighbors.push_back(node_ptr);
    }
  }
}

RouteModel::Node &RouteModel::FindClosestNode(float x, float y) {
  RouteModel::Node tempNode;
  tempNode.x = x;
  tempNode.y = y;
  float minDist = numeric_limits<float>::max();
  float curDist = 0.0;
  int closestIdx = 0l

      for (const Model::Road &road : Roads()) {
    if (road.type != Model::Road::Type::Footway) {
      for (int node_idx : Ways()[road.way].nodes) {
        curDist = SNodes()[node_idx].distance(tempNode);
        if (minDist > curDist) {
          minDist = curDist;
          closestIdx = node_idx;
        }
      }
    }
  }
  return SNodes()[closestIdx];
}