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

int main(int, char **) {
  VideoCapture capture(0);
  int frame_rate = 10;
  for (int i = 0; i < 4; i++) // for infinite loop remove iteration
  {
    time_t timer_start, timer_stop;
    Mat frame;
    stringstream recordstr;
    recordstr << "records/" << i << ".avi";
    string recordfile = recordstr.str();

    VideoWriter video(recordfile, CV_FOURCC('M', 'J', 'P', 'G'), frame_rate,
                      Size(frame_width, frame_height), true);

    cout << "video " << i << ".avi started capturing at " << currentDateTime()
         << endl;
    time(&timer_start);
    for (int j = 0; j < numFrames; j++) {
      capture >> frame;
      if (frame.empty()) {
        cout << "Failed to capture an image" << endl;
        return -1;
      }
      video.write(frame);
    }
    time(&timer_stop);
    double timeDifference = difftime(timer_stop, timer_start);
    cout << "video " << i << ".avi stopped capturing at " << currentDateTime()
         << " & took " << timeDifference << " seconds" << endl;
    sleep(60);
  }
  return 0;
}