//
// Created by Ahsan Ghani on 2022-10-31.
//
#include <iostream>
#include <thread>
#include <vector>

#include "Graphics.h"
#include "Intersection.h"
#include "Street.h"
#include "Vehicle.h"

using namespace std;

void createTrafficObjects_Paris(vector<shared_ptr<Street>> &streets,
                                vector<shared_ptr<Intersection>> &intersections,
                                vector<shared_ptr<Vehicle>> &vehicles,
                                string &filename, int nVehicles) {
  filename = "../data/paris.jpg";
  int nIntersections = 9;
  for (size_t ni = 0; ni < nIntersections; ni++) {
    intersections.push_back(make_shared<Intersection>());
  }

  intersections.at(0)->setPosition(385, 270);
  intersections.at(1)->setPosition(1240, 80);
  intersections.at(2)->setPosition(1625, 75);
  intersections.at(3)->setPosition(2110, 75);
  intersections.at(4)->setPosition(2840, 175);
  intersections.at(5)->setPosition(3070, 680);
  intersections.at(6)->setPosition(2800, 1400);
  intersections.at(7)->setPosition(400, 1100);
  intersections.at(8)->setPosition(1700, 900); // central plaza

  int nStreets = 8;
  for (size_t ns = 0; ns < nStreets; ns++) {
    streets.push_back(make_shared<Street>());
    streets.at(ns)->setInIntersection(intersections.at(ns));
    streets.at(ns)->setOutIntersection(intersections.at(8));
  }

  for (size_t nv = 0; nv < nVehicles; nv++) {
    vehicles.push_back(make_shared<Vehicle>());
    vehicles.at(nv)->setCurrentStreet(streets.at(nv));
    vehicles.at(nv)->setCurrentDestination(intersections.at(8));
  }
}
