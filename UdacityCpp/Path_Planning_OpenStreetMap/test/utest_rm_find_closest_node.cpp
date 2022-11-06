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
  if (!is) {
    return nullopt;
  }

  auto size = is.tellg();
  vector<byte> contents(size);

  is.seekg(0);
  is.read((char *)contents.data(), size);

  if (contents.empty()) {
    return nullopt;
  }
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