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

static std::optional<std::vector<std::byte>> ReadFile(const std::string &path) {
  std::ifstream is{path, std::ios::binary | std::ios::ate};
  if (!is)
    return std::nullopt;

  auto size = is.tellg();
  std::vector<std::byte> contents(size);

  is.seekg(0);
  is.read((char *)contents.data(), size);

  if (contents.empty())
    return std::nullopt;
  return std::move(contents);
}

std::vector<std::byte> ReadOSMData(const std::string &path) {
  std::vector<std::byte> osm_data;
  auto data = ReadFile(path);
  if (!data) {
    std::cout << "Failed to read OSM data." << std::endl;
  } else {
    osm_data = std::move(*data);
  }
  return osm_data;
}

class RouteModelTest : public ::testing::Test {
protected:
  std::string osm_data_file = "../map.osm";
  std::vector<std::byte> osm_data = ReadOSMData(osm_data_file);
  RouteModel model{osm_data};
};

TEST_F(RouteModelTest, RouteModelData) {
  EXPECT_EQ(model.path.size(), 0);
  EXPECT_EQ(model.Nodes().size(), model.SNodes().size());
}