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