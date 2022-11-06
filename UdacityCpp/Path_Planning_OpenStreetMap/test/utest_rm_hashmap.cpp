//
// Created by Ahsan Ghani on 2022-11-03.
//
#include "../src/route_model.h"
#include "../src/route_planner.h"
#include "gtest/gtest.h"
#include <fstream>
#include <iostream>
#include <optional>
#include <vector>

using namespace std;

static optional<vector<byte>> ReadFile(const string &path) {
  ifstream is{path, ios::binary | ios::ate};
  if (!is)
    return nullopt;

  auto size = is.tellg();
  vector<byte> contents(size);

  is.seekg(0);
  is.read((char *)contents.data(), size);

  if (contents.empty())
    return nullopt;
  return move(contents);
}

vector<byte> ReadOSMData(const string &path) {
  vector<byte> osm_data;
  auto data = ReadFile(path);
  if (!data) {
    cout << "Failed to read OSM data." << endl;
  } else {
    osm_data = move(*data);
  }
  return osm_data;
}

class RouteModelTest : public ::testing::Test {
protected:
  string osm_data_file = "../map.osm";
  vector<byte> osm_data = ReadOSMData(osm_data_file);
  RouteModel model{osm_data};
};

TEST_F(RouteModelTest, RouteModelData) {
  EXPECT_EQ(model.path.size(), 0);
  EXPECT_EQ(model.Nodes().size(), model.SNodes().size());
}

TEST_F(RouteModelTest, RouteModelNode) {
  RouteModel::Node test_node = model.SNodes()[1];
  EXPECT_FLOAT_EQ(test_node.x, 1.2646476);
  EXPECT_FLOAT_EQ(test_node.y, 0.23506972);
  EXPECT_EQ(test_node.parent, nullptr);
  EXPECT_FLOAT_EQ(test_node.h_value, numeric_limits<float>::max());
  EXPECT_FLOAT_EQ(test_node.g_value, 0.0);
  EXPECT_FLOAT_EQ(test_node.visited, false);
  EXPECT_EQ(test_node.neighbors.size(), 0);
  RouteModel::Node test_node_2 = RouteModel::Node();
}

TEST_F(RouteModelTest, NodeDistance) {
  RouteModel::Node test_node = model.SNodes()[1];
  RouteModel::Node test_node_2 = model.SNodes()[4];
  EXPECT_FLOAT_EQ(test_node.distance(test_node_2), 0.10309877);
}

TEST_F(RouteModelTest, NodeToRoad) {
  auto node_to_road = model.GetNodeToRoadMap();
  EXPECT_EQ(node_to_road[0].size(), 2);
  EXPECT_EQ(node_to_road[30].size(), 2);
  EXPECT_EQ(node_to_road[90].size(), 2);
  EXPECT_EQ(node_to_road[0][0]->way, 500);
  EXPECT_EQ(node_to_road[30][1]->way, 613);
  EXPECT_EQ(node_to_road[90][1]->way, 475);
}
