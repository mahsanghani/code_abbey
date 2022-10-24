//
// Created by Ahsan Ghani on 2022-10-23.
//
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

enum class State { kEmpty, kObstacle, kClosed, kPath, kStart, kFinish };

const int delta[4][2]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};