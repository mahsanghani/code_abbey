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