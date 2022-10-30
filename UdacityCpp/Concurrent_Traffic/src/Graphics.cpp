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