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

int main(int argc, const char **argv) {
  string osm_data_file = "";
  if (argc > 1) {
    for (int i = 1; i < argc; ++i)
      if (string_view{argv[i]} == "-f" && ++i < argc)
        osm_data_file = argv[i];
  } else {
    cout << "Usage: [executable] [-f filename.osm]" << endl;
  }

  vector<byte> osm_data;

  if (osm_data.empty() && !osm_data_file.empty()) {
    cout << "Reading OpenStreetMap data from the following file: "
         << osm_data_file << endl;
    auto data = ReadFile(osm_data_file);
    if (!data)
      cout << "Failed to read." << endl;
    else
      osm_data = move(*data);
  }

  float start_x, start_y, end_x, end_y;
  cout << "Please type in start_x from 0-100 : " << endl;
  cin >> start_x;
  while (!(cin) || start_x < 0 || start_x > 100) {
    cout << "Invalid entry. Enter a start_x from 0 to 100: ";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> start_x;
  }
  cout << "Please type in start_y from 0-100 : " << endl;
  cin >> start_y;
  while (!(cin) || start_y < 0 || start_y > 100) {
    cout << "Invalid entry. Enter a start_y from 0 to 100: ";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> start_y;
  }
  cout << "Please type in end_x from 0-100 : " << endl;
  cin >> end_x;
  while (!(cin) || end_x < 0 || end_x > 100) {
    cout << "Invalid entry. Enter a end_x from 0 to 100: ";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> end_x;
  }
  cout << "Please type in end_y from 0-100 : " << endl;
  cin >> end_y;
  while (!(cin) || end_y < 0 || end_y > 100) {
    cout << "Invalid entry. Enter a end_y from 0 to 100: ";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> end_y;
  }

  RouteModel model{osm_data};

  RoutePlanner route_planner{model, start_x, start_y, end_x, end_y};

  route_planner.AStarSearch();
  cout << "The total distance is : " << route_planner.GetDistance() << endl;

  Render render{model};

  auto display = io2d::output_surface{400,
                                      400,
                                      io2d::format::argb32,
                                      io2d::scaling::none,
                                      io2d::refresh_style::fixed,
                                      30};
  display.size_change_callback([](io2d::output_surface &surface) {
    surface.dimensions(surface.display_dimensions());
  });
  display.draw_callback(
      [&](io2d::output_surface &surface) { render.Display(surface); });
  display.begin_show();
}
