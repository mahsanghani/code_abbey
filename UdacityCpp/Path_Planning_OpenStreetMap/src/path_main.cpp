//
// Created by Ahsan Ghani on 2022-11-03.
//
#include "render.h"
#include "route_model.h"
#include "route_planner.h"
#include <fstream>
#include <io2d.h>
#include <iostream>
#include <limits>
#include <optional>
#include <string>
#include <vector>

using namespace std;
using namespace experimental;

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