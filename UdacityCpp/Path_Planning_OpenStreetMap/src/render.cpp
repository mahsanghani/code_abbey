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

void Render::DrawEndPosition(io2d::output_surface &surface) const {
  io2d::render_props aliased{io2d::antialias::none};
  io2d::brush foreBrush{io2d::rgba_color::red};

  auto pb = io2d::path_builder{};
  pb.matrix(m_Matrix);

  pb.new_figure({(float)m_Model.path.front().x, (float)m_Model.path.front().y});
  float constexpr l_marker = 0.01f;
  pb.rel_line({l_marker, 0.f});
  pb.rel_line({0.f, l_marker});
  pb.rel_line({-l_marker, 0.f});
  pb.rel_line({0.f, -l_marker});
  pb.close_figure();

  surface.fill(foreBrush, pb);
  surface.stroke(foreBrush, io2d::interpreted_path{pb}, std::nullopt,
                 std::nullopt, std::nullopt, aliased);
}

void Render::DrawStartPosition(io2d::output_surface &surface) const {
  io2d::render_props aliased{io2d::antialias::none};
  io2d::brush foreBrush{io2d::rgba_color::green};

  auto pb = io2d::path_builder{};
  pb.matrix(m_Matrix);

  pb.new_figure({(float)m_Model.path.back().x, (float)m_Model.path.back().y});
  float constexpr l_marker = 0.01f;
  pb.rel_line({l_marker, 0.f});
  pb.rel_line({0.f, l_marker});
  pb.rel_line({-l_marker, 0.f});
  pb.rel_line({0.f, -l_marker});
  pb.close_figure();

  surface.fill(foreBrush, pb);
  surface.stroke(foreBrush, io2d::interpreted_path{pb}, std::nullopt,
                 std::nullopt, std::nullopt, aliased);
}

void Render::DrawBuildings(io2d::output_surface &surface) const {
  for (auto &building : m_Model.Buildings()) {
    auto path = PathFromMP(building);
    surface.fill(m_BuildingFillBrush, path);
    surface.stroke(m_BuildingOutlineBrush, path, std::nullopt,
                   m_BuildingOutlineStrokeProps);
  }
}

void Render::DrawLeisure(io2d::output_surface &surface) const {
  for (auto &leisure : m_Model.Leisures()) {
    auto path = PathFromMP(leisure);
    surface.fill(m_LeisureFillBrush, path);
    surface.stroke(m_LeisureOutlineBrush, path, std::nullopt,
                   m_LeisureOutlineStrokeProps);
  }
}

void Render::DrawWater(io2d::output_surface &surface) const {
  for (auto &water : m_Model.Waters())
    surface.fill(m_WaterFillBrush, PathFromMP(water));
}

void Render::DrawLanduses(io2d::output_surface &surface) const {
  for (auto &landuse : m_Model.Landuses())
    if (auto br = m_LanduseBrushes.find(landuse.type);
        br != m_LanduseBrushes.end())
      surface.fill(br->second, PathFromMP(landuse));
}

void Render::DrawHighways(io2d::output_surface &surface) const {
  auto ways = m_Model.Ways().data();
  for (auto road : m_Model.Roads())
    if (auto rep_it = m_RoadReps.find(road.type); rep_it != m_RoadReps.end()) {
      auto &rep = rep_it->second;
      auto &way = ways[road.way];
      auto width =
          rep.metric_width > 0.f ? (rep.metric_width * m_PixelsInMeter) : 1.f;
      auto sp = io2d::stroke_props{width, io2d::line_cap::round};
      surface.stroke(rep.brush, PathFromWay(way), std::nullopt, sp, rep.dashes);
    }
}

void Render::DrawRailways(io2d::output_surface &surface) const {
  auto ways = m_Model.Ways().data();
  for (auto &railway : m_Model.Railways()) {
    auto &way = ways[railway.way];
    auto path = PathFromWay(way);
    surface.stroke(m_RailwayStrokeBrush, path, std::nullopt,
                   io2d::stroke_props{m_RailwayOuterWidth * m_PixelsInMeter});
    surface.stroke(m_RailwayDashBrush, path, std::nullopt,
                   io2d::stroke_props{m_RailwayInnerWidth * m_PixelsInMeter},
                   m_RailwayDashes);
  }
}

io2d::interpreted_path Render::PathLine() const {
  if (m_Model.path.empty())
    return {};

  const auto nodes = m_Model.path;

  auto pb = io2d::path_builder{};
  pb.matrix(m_Matrix);
  pb.new_figure(ToPoint2D(m_Model.path[0]));

  for (int i = 1; i < m_Model.path.size(); i++)
    pb.line(ToPoint2D(m_Model.path[i]));

  return io2d::interpreted_path{pb};
}

io2d::interpreted_path Render::PathFromWay(const Model::Way &way) const {
  if (way.nodes.empty())
    return {};

  const auto nodes = m_Model.Nodes().data();

  auto pb = io2d::path_builder{};
  pb.matrix(m_Matrix);
  pb.new_figure(ToPoint2D(nodes[way.nodes.front()]));
  for (auto it = ++way.nodes.begin(); it != std::end(way.nodes); ++it)
    pb.line(ToPoint2D(nodes[*it]));
  return io2d::interpreted_path{pb};
}
