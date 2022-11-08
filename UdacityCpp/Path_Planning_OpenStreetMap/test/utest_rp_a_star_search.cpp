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

TEST_F(RouteModelTest, FindNeighbors) {
  auto test_node = model.SNodes()[0];
  test_node.FindNeighbors();
  EXPECT_EQ(test_node.neighbors.size(), 2);
  EXPECT_FLOAT_EQ(test_node.neighbors[1]->x, 1.3250526);
  EXPECT_FLOAT_EQ(test_node.neighbors[1]->y, 0.41849667);
  test_node.neighbors.clear(); // Clear out neighbors just added.
  test_node = model.SNodes()[100];
  test_node.FindNeighbors();
  EXPECT_EQ(test_node.neighbors.size(), 2);
  EXPECT_FLOAT_EQ(test_node.neighbors[0]->x, 0.77367586);
  EXPECT_FLOAT_EQ(test_node.neighbors[0]->y, 0.52004427);
  test_node.neighbors.clear();
}

TEST_F(RouteModelTest, FindClosestNode) {
  float x = 0.023456;
  float y = 0.567890;
  auto &test_node = model.FindClosestNode(x, y);
  EXPECT_EQ(&test_node, &model.SNodes()[10155]);
  EXPECT_FLOAT_EQ(test_node.x, 0.030928569);
  EXPECT_FLOAT_EQ(test_node.y, 0.58042318);
  x = 0.555555;
  y = 0.333333;
  auto &test_node_2 = model.FindClosestNode(x, y);
  EXPECT_EQ(&test_node_2, &model.SNodes()[600]);
  EXPECT_FLOAT_EQ(test_node_2.x, 0.58249766);
  EXPECT_FLOAT_EQ(test_node_2.y, 0.34965551);
}

class RoutePlannerTest : public ::testing::Test {
protected:
  string osm_data_file = "../map.osm";
  vector<byte> osm_data = ReadOSMData(osm_data_file);
  RouteModel model{osm_data};
  RoutePlanner route_planner{model, 10, 10, 90, 90};

  // Construct start_node and end_node as in the model.
  float start_x = 0.1;
  float start_y = 0.1;
  float end_x = 0.9;
  float end_y = 0.9;
  RouteModel::Node *start_node = &model.FindClosestNode(start_x, start_y);
  RouteModel::Node *end_node = &model.FindClosestNode(end_x, end_y);
};

TEST_F(RoutePlannerTest, AStarSearch) {
  route_planner.AStarSearch();
  EXPECT_EQ(model.path.size(), 33);
  RouteModel::Node path_start = model.path.back();
  RouteModel::Node path_end = model.path.front();
  // The start_node and end_node x, y values should be the same as in the path.
  EXPECT_FLOAT_EQ(start_node->x, path_start.x);
  EXPECT_FLOAT_EQ(start_node->y, path_start.y);
  EXPECT_FLOAT_EQ(end_node->x, path_end.x);
  EXPECT_FLOAT_EQ(end_node->y, path_end.y);
  EXPECT_FLOAT_EQ(route_planner.GetDistance(), 873.41565);
}
