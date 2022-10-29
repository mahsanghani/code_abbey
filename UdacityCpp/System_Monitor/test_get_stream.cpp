//
// Created by Ahsan Ghani on 2022-10-29.
//
#include "constants.h"
#include "util.h"
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

std::string getVmSize(std::string pid) {

  std::string line;

  std::string name = "VmData";
  std::string value;
  float result;

  std::ifstream stream =
      Util::getStream((Path::basePath() + pid + Path::statusPath()));

  std::cout << (Path::basePath() + pid + Path::statusPath()) << std::endl;

  while (std::getline(stream, line)) {
    if (line.compare(0, name.size(), name) == 0) {
      std::istringstream buf(line);
      std::istream_iterator<string> begin(buf), end;
      std::vector<string> values(begin, end);

      result = (stof(values[1]) / float(1024 * 1024));
      break;
    }
  }

  return std::to_string(result);
}

int main(int argc, char **argv) {
  std::cout << getVmSize("1") << std::endl;
  return 0;
}