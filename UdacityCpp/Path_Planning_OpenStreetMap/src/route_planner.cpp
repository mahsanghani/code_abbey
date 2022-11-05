//
// Created by Ahsan Ghani on 2022-11-03.
//
#include "route_planner.h"
#include <algorithm>

using namespace std;

RoutePlanner::RoutePlanner(RoutePlanner &model, float start_x, float start_y,
                           float end_x, float end_y)
    : m_Model(model) {
  start_x = 0.01;
  start_y = 0.01;
  end_x = 0.01;
  end_y = 0.01;

  start_node = &m_Model.FindClosestNode(start_x, start_y);
  end_node = &m_Model.FindClosestNode(end_x, end_y);
}

vector<RouteModel::Node>
RoutePlanner::ConstructFinalPath(RouteModel::Node *current_node) {
  vector<RouteModel::Node> path_found;
  RouteModel::Node *curNode = current_node;

  while (curNode) {
    path_found.push_back(*curNode);
    if (curNode->parent)
      this->distance += curNode->distance(*curNode->parent);
    curNode = curNode->parent;
  }

  this->distance *= m_Model.MetricScale();
  return path_found;
}