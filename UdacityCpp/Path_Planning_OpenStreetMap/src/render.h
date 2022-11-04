//
// Created by Ahsan Ghani on 2022-11-03.
//
#pragma once

#include "route_model.h"
#include <io2d.h>
#include <unordered_map>

using namespace std::experimental;

class Render {
public:
  Render(RouteModel &model);
  void Display(io2d::output_surface &surface);

private:
  void BuildRoadReps();
  void BuildLanduseBrushes();

  void DrawBuildings(io2d::output_surface &surface) const;
  void DrawHighways(io2d::output_surface &surface) const;
  void DrawRailways(io2d::output_surface &surface) const;
  void DrawLeisure(io2d::output_surface &surface) const;
  void DrawWater(io2d::output_surface &surface) const;
  void DrawLanduses(io2d::output_surface &surface) const;
  void DrawStartPosition(io2d::output_surface &surface) const;
  void DrawEndPosition(io2d::output_surface &surface) const;
  void DrawPath(io2d::output_surface &surface) const;
  io2d::interpreted_path PathFromWay(const Model::Way &way) const;
  io2d::interpreted_path PathFromMP(const Model::Multipolygon &mp) const;
  io2d::interpreted_path PathLine() const;
};