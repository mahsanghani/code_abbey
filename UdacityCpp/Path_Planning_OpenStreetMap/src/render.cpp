//
// Created by Ahsan Ghani on 2022-11-03.
//
#include "render.h"
#include <iostream>

using namespace std;

static float RoadMetricWidth(Model::Road::Type type);
static io2d::rgba_color RoadColor(Model::Road::Type type);
static io2d::dashes RoadDashes(Model::Road::Type type);
static io2d::point_2d ToPoint2D(const Model::Node &node) noexcept;

Render::Render(RouteModel &model) : m_Model(model) {
  BuildRoadReps();
  BuildLanduseBrushes();
}
