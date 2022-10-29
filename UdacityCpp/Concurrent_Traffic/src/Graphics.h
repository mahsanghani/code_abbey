//
// Created by Ahsan Ghani on 2022-10-29.
//
#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "TrafficObject.h"
#include <opencv2/core.hpp>
#include <string>
#include <vector>

class Graphics {
public:
  void setBgFilename(std::string filename) { _bgFilename = filename; }
  void setTrafficObjects(
      std::vector<std::shared_ptr<TrafficObject>> &trafficObjects) {
    _trafficObjects = trafficObjects;
  };

  void simulate();

private:
  void loadBackgroundImg();
  void drawTrafficObjects();

  std::vector<std::shared_ptr<TrafficObject>> _trafficObjects;
  std::string _bgFilename;
  std::string _windowName;
  std::vector<cv::Mat> _images;
};

#endif