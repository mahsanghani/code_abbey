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

void createTrafficObjects_NYC(vector<shared_ptr<Street>> &streets,
                              vector<shared_ptr<Intersection>> &intersections,
                              vector<shared_ptr<Vehicle>> &vehicles,
                              string &filename, int nVehicles) {
  filename = "../data/nyc.jpg";

  int nIntersections = 6;
  for (size_t ni = 0; ni < nIntersections; ni++) {
    intersections.push_back(make_shared<Intersection>());
  }

  intersections.at(0)->setPosition(1430, 625);
  intersections.at(1)->setPosition(2575, 1260);
  intersections.at(2)->setPosition(2200, 1950);
  intersections.at(3)->setPosition(1000, 1350);
  intersections.at(4)->setPosition(400, 1000);
  intersections.at(5)->setPosition(750, 250);

  int nStreets = 7;
  for (size_t ns = 0; ns < nStreets; ns++) {
    streets.push_back(make_shared<Street>());
  }

  streets.at(0)->setInIntersection(intersections.at(0));
  streets.at(0)->setOutIntersection(intersections.at(1));

  streets.at(1)->setInIntersection(intersections.at(1));
  streets.at(1)->setOutIntersection(intersections.at(2));

  streets.at(2)->setInIntersection(intersections.at(2));
  streets.at(2)->setOutIntersection(intersections.at(3));

  streets.at(3)->setInIntersection(intersections.at(3));
  streets.at(3)->setOutIntersection(intersections.at(4));

  streets.at(4)->setInIntersection(intersections.at(4));
  streets.at(4)->setOutIntersection(intersections.at(5));

  streets.at(5)->setInIntersection(intersections.at(5));
  streets.at(5)->setOutIntersection(intersections.at(0));

  streets.at(6)->setInIntersection(intersections.at(0));
  streets.at(6)->setOutIntersection(intersections.at(3));

  for (size_t nv = 0; nv < nVehicles; nv++) {
    vehicles.push_back(make_shared<Vehicle>());
    vehicles.at(nv)->setCurrentStreet(streets.at(nv));
    vehicles.at(nv)->setCurrentDestination(intersections.at(nv));
  }
}
