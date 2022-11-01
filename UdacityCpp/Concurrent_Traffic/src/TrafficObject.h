//
// Created by Ahsan Ghani on 2022-10-31.
//
#ifndef TRAFFICOBJECT_H
#define TRAFFICOBJECT_H

#include <mutex>
#include <thread>
#include <vector>

using namespace std;

enum ObjectType {
  noObject,
  objectVehicle,
  objectIntersection,
  objectStreet,
};

class TrafficObject {
public:
  TrafficObject();
  ~TrafficObject();

  int getID() { return id_; }
  void setPosition(double x, double y);
  void getPosition(double &x, double &y);
  ObjectType getType() { return type_; }

  virtual void simulate(){};

protected:
  ObjectType type_;
  int id_;
  double posX_, posY_;
  std::vector<std::thread> threads_;
  static std::mutex mtx_;

private:
  static int id_cnt_;
};

#endif