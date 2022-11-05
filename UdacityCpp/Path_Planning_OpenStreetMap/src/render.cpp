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

void Render::Display(io2d::output_surface &surface) {
  m_Scale = static_cast<float>(
      std::min(surface.dimensions().x(), surface.dimensions().y()));
  m_PixelsInMeter = static_cast<float>(m_Scale / m_Model.MetricScale());
  m_Matrix = io2d::matrix_2d::create_scale({m_Scale, -m_Scale}) *
             io2d::matrix_2d::create_translate(
                 {0.f, static_cast<float>(surface.dimensions().y())});

  surface.paint(m_BackgroundFillBrush);
  DrawLanduses(surface);
  DrawLeisure(surface);
  DrawWater(surface);
  DrawRailways(surface);
  DrawHighways(surface);
  DrawBuildings(surface);
  DrawPath(surface);
  DrawStartPosition(surface);
  DrawEndPosition(surface);
}

void Render::DrawPath(io2d::output_surface &surface) const {
  io2d::render_props aliased{io2d::antialias::none};
  io2d::brush foreBrush{io2d::rgba_color::orange};
  float width = 5.0f;
  surface.stroke(foreBrush, PathLine(), std::nullopt,
                 io2d::stroke_props{width});
}