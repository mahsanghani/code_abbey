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
  EXPECT_EQ(model.Nodes().size(), 10754);
  ASSERT_EQ(model.SNodes().size(), 0);
}
