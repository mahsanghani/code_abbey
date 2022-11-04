//
// Created by Ahsan Ghani on 2022-11-03.
//
#pragma once

#include "route_model.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class RoutePlanner {
public:
  RoutePlanner(RoutePlanner &model, float start_x, float start_y, float end_x,
               float end_y);
  float GetDistance() { return distance; }
  void AStarSearch();

private:
  RouteModel &m_Model;
  RouteModel::Node *start_node;
  RouteModel::Node *end_node;
  float distance = 0.0f;
  vector<RouteModel::Node *> open_list;

  vector<RouteModel::Node> ConstructFinalPath(RouteModel::Node *);
  float CalculateHValue(const RouteModel::Node *node);
  RouteModel::Node *NextNode();
  static bool compareFValue(const RouteModel::Node *node_a,
                            const RouteModel::Node *node_b);
  void AddNeighbors(RouteModel::Node *);
};