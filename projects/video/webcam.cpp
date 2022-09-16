//
// Created by Ahsan Ghani on 2022-09-15.
//
#include <ctime>
#include <iostream>
#include <opencv/cv.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <sstream>
#include <string>
#include <unistd.h>

using namespace std;
using namespace cv;

string currentDateTime() {
  time_t now = time(0);
  struct tm tstruct;
  char buf[80];
  tstruct = *localtime(&now);
  strftime(buf, sizeof(buf), "%X", &tstruct);
  return buf;
}
