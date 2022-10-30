//
// Created by Ahsan Ghani on 2022-10-29.
//
#include "Graphics.h"
#include "Intersection.h"
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;

void Graphics::simulate() {
  this->loadBackgroundImg();
  while (true) {
    this_thread::sleep_for(chrono::milliseconds(1));
    this->drawTrafficObjects();
  }
}

void Graphics::loadBackgroundImg() {
  _windowName = "Concurrency Traffic Simulation";
  cv::namedWindow(_windowName, cv::WINDOW_NORMAL);

  cv::Mat background = cv::imread(_bgFilename);
  _images.push_back(background);
  _images.push_back(background.clone());
  _images.push_back(background.clone());
}