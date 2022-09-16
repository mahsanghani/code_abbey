//
// Created by Ahsan Ghani on 2022-09-15.
//
#include "opencv2/opencv.hpp"
#include <cstdio>
#include <ctime>
#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;
using namespace cv;

int main() {

  time_t start, end;
  VideoCapture vcap(0);
  if (!vcap.isOpened()) {
    cout << "Error opening video stream or file" << endl;
    return -1;
  }
  int frame_width = vcap.get(CV_CAP_PROP_FRAME_WIDTH);
  int frame_height = vcap.get(CV_CAP_PROP_FRAME_HEIGHT);
  VideoWriter video(
      "C:\\Users\\lenovo\\Desktop\\OpenCV Webcam Video Record With R "
      "Key\\WebcamRecorder\\WebcamRecorder\\data\\MyVideo.avi",
      CV_FOURCC('M', 'J', 'P', 'G'), 10, Size(frame_width, frame_height), true);
  time(&start);

  for (;;) {

    Mat frame;
    vcap >> frame;
    video.write(frame);
    imshow("Frame", frame);
    char c = (char)waitKey(33);
    if (c == 27)
      break;

    time(&end);
    double dif = difftime(end, start);
    printf("Elasped time is %.2lf seconds.", dif);
    if (dif == 10) {
      std::cout << "DONE" << dif << std::endl;
      break;
    }
  }
  return 0;
}