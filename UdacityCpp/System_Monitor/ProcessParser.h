//
// Created by Ahsan Ghani on 2022-10-29.
//
#ifndef PROCESS_PARSER_H
#define PROCESS_PARSER_H

#include "constants.h"
#include "util.h"
#include <algorithm>
#include <cerrno>
#include <chrono>
#include <cstring>
#include <dirent.h>
#include <fstream>
#include <iostream>
#include <iterator>
#include <math.h>
#include <sstream>
#include <stdexcept>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <thread>
#include <time.h>
#include <unistd.h>
#include <vector>

class ProcessParser {
private:
  std::ifstream stream;

public:
  static std::string getCmd(std::string pid);
  static std::vector<std::string> getPidList();
  static std::string getVmSize(std::string pid);
  static std::string getCpuPercent(std::string pid);
  static long int getSysUpTime();
  static std::string getProcUpTime(std::string pid);
  static std::string getProcUser(std::string pid);
  static std::vector<std::string> getSysCpuPercent(std::string coreNumber = "");
  static float getSysRamPercent();
  static std::string getSysKernelVersion();
  static int getNumberOfCores();
  static int getTotalThreads();
  static int getTotalNumberOfProcesses();
  static int getNumberOfRunningProcesses();
  static std::string getOSName();
  static std::string PrintCpuStats(std::vector<std::string> values1,
                                   std::vector<std::string> values2);
  static bool isPidExisting(std::string pid);
  static float getSysActiveCpuTime(std::vector<std::string> values);
  static float getSysIdleCpuTime(std::vector<std::string> values);
  static float generateMemory(std::string line);
};

std::string ProcessParser::getVmSize(std::string pid) {

  std::string line;

  std::string name = "VmData";
  std::string value;
  float result;

  std::ifstream stream =
      Util::getStream((Path::basePath() + pid + Path::statusPath()));

  while (std::getline(stream, line)) {
    if (line.compare(0, name.size(), name) == 0) {
      std::istringstream buf(line);
      std::istream_iterator<std::string> begin(buf), end;
      std::vector<std::string> values(begin, end);

      result = (stof(values[1]) / float(1024 * 1024));
      break;
    }
  }

  return std::to_string(result);
}

std::string ProcessParser::getCpuPercent(std::string pid) {

  std::string line;

  std::ifstream stream =
      Util::getStream((Path::basePath() + pid + "/" + Path::statPath()));

  std::getline(stream, line);
  std::istringstream buf(line);
  std::istream_iterator<std::string> begin(buf), end;
  std::vector<std::string> values(begin, end);

  float utime = stof(ProcessParser::getProcUpTime(pid));
  float stime = stof(values[14]);
  float cutime = stof(values[15]);
  float cstime = stof(values[16]);
  float starttime = stof(values[21]);
  float uptime = ProcessParser::getSysUpTime();
  float freq = sysconf(_SC_CLK_TCK);
  float total_time = utime + stime + cutime + cstime;
  float seconds = uptime - (starttime / freq);
  float result = 100.0 * ((total_time / freq) / seconds);

  return std::to_string(result);
}

std::string ProcessParser::getProcUpTime(std::string pid) {
  std::string line;
  std::string value;

  std::ifstream stream =
      Util::getStream((Path::basePath() + pid + "/" + Path::statPath()));

  std::getline(stream, line);
  std::istringstream buf(line);
  std::istream_iterator<std::string> begin(buf), end;
  std::vector<std::string> values(begin, end);

  return std::to_string(float(stof(values[13]) / sysconf(_SC_CLK_TCK)));
}

long int ProcessParser::getSysUpTime() {
  std::string line;
  std::string value;

  std::ifstream stream =
      Util::getStream((Path::basePath() + Path::upTimePath()));

  std::getline(stream, line);
  std::istringstream buf(line);
  std::istream_iterator<std::string> begin(buf), end;
  std::vector<std::string> values(begin, end);

  return stoi(values[0]);
}

std::string ProcessParser::getProcUser(std::string pid) {
  std::string line;

  std::string name = "Uid"; // TODO: confirm if I have to use "Uid:"
  std::string result = "";
  std::ifstream stream =
      Util::getStream((Path::basePath() + pid + Path::statusPath()));

  while (std::getline(stream, line)) {
    if (line.compare(0, name.size(), name) == 0) {
      std::istringstream buf(line);
      std::istream_iterator<std::string> begin(buf), end;
      std::vector<std::string> values(begin, end);
      result = values[1];
      break;
    }
  }
  stream = Util::getStream("/etc/passwd");
  name = "x:" + result;

  while (std::getline(stream, line)) {
    if (line.find(name) != std::string::npos) {
      result = line.substr(0, line.find(":"));
      return result;
    }
  }

  return "";
}

std::vector<std::string> ProcessParser::getPidList() {

  DIR *dir;

  std::vector<std::string> container;

  if (!(dir = opendir("/proc"))) {
    throw std::runtime_error(std::strerror(errno));
  }

  while (dirent *dirp = readdir(dir)) {
    if (dirp->d_type != DT_DIR)
      continue;

    if (all_of(dirp->d_name, dirp->d_name + std::strlen(dirp->d_name),
               [](char c) { return std::isdigit(c); })) {
      container.push_back(dirp->d_name);
    }
  }

  if (closedir(dir)) {
    throw std::runtime_error(std::strerror(errno));
  }

  return container;
}

std::string ProcessParser::getCmd(std::string pid) {
  string line;
  std::ifstream stream =
      Util::getStream((Path::basePath() + pid + Path::cmdPath()));
  std::getline(stream, line);

  return line;
}

int ProcessParser::getNumberOfCores() {
  std::string line;
  std::string name = "cpu cores";
  std::ifstream stream =
      Util::getStream(Path::basePath() + Path::cpuInfoPath());

  while (std::getline(stream, line)) {
    if (line.compare(0, name.size(), name) == 0) {
      std::istringstream buf(line);
      std::istream_iterator<std::string> begin(buf), end;
      std::vector<std::string> values(begin, end);

      return stoi(values[3]);
    }
  }
}

std::vector<std::string>
ProcessParser::getSysCpuPercent(std::string core_number) {
  std::string line;
  std::string name = "cpu" + core_number;
  std::ifstream stream = Util::getStream(Path::basePath() + Path::statPath());

  while (std::getline(stream, line)) {
    if (line.compare(0, name.size(), name) == 0) {
      std::istringstream buf(line);
      std::istream_iterator<std::string> begin(buf), end;
      std::vector<std::string> values(begin, end);

      return values;
    }
  }

  return std::vector<std::string>();
}

std::string ProcessParser::PrintCpuStats(std::vector<std::string> values_1,
                                         std::vector<std::string> values_2) {
  float active_time = ProcessParser::getSysActiveCpuTime(values_2) -
                      ProcessParser::getSysActiveCpuTime(values_1);
  float idle_time = ProcessParser::getSysIdleCpuTime(values_2) -
                    ProcessParser::getSysIdleCpuTime(values_1);

  float total_time = active_time + idle_time;
  float result = 100.0 * (active_time / total_time);
  return std::to_string(result);
}

bool ProcessParser::isPidExisting(std::string pid) {
  std::vector<std::string> pid_list = ProcessParser::getPidList();
  if (std::find(pid_list.begin(), pid_list.end(), pid) != pid_list.end())
    return true;
  else
    return false;
}

float ProcessParser::getSysActiveCpuTime(std::vector<std::string> values) {
  return (stof(values[S_USER]) + stof(values[S_NICE]) + stof(values[S_SYSTEM]) +
          stof(values[S_IRQ]) + stof(values[S_SOFTIRQ]) +
          stof(values[S_STEAL]) + stof(values[S_GUEST]) +
          stof(values[S_GUEST_NICE]));
}

float ProcessParser::getSysIdleCpuTime(std::vector<std::string> values) {
  return (stof(values[S_IDLE]) + stof(values[S_IOWAIT]));
}

float ProcessParser::getSysRamPercent() {
  std::string line;
  std::string name_1 = "MemAvailable:";
  std::string name_2 = "MemFree:";
  std::string name_3 = "Buffers:";

  std::string value;
  int result;
  std::ifstream stream =
      Util::getStream((Path::basePath() + Path::memInfoPath()));
  float total_mem = 0;
  float free_mem = 0;
  float buffers = 0;

  while (std::getline(stream, line)) {
    if (total_mem != 0 && free_mem != 0)
      break;

    if (line.compare(0, name_1.size(), name_1) == 0) {
      total_mem = ProcessParser::generateMemory(line);
    }

    if (line.compare(0, name_2.size(), name_2) == 0) {
      free_mem = ProcessParser::generateMemory(line);
    }

    if (line.compare(0, name_3.size(), name_3) == 0) {
      buffers = ProcessParser::generateMemory(line);
    }
  }

  return float(100 * (1 - free_mem / (total_mem - buffers)));
}

float ProcessParser::generateMemory(std::string line) {
  std::istringstream buf(line);
  std::istream_iterator<std::string> begin(buf), end;
  std::vector<std::string> values(begin, end);

  return stof(values[1]);
}

std::string ProcessParser::getSysKernelVersion() {
  std::string line;
  std::string name =
      "Linux version"; // TODO: just erase a ' '(space) in the end
  std::ifstream stream =
      Util::getStream((Path::basePath() + Path::versionPath()));

  while (std::getline(stream, line)) {
    if (line.compare(0, name.size(), name) == 0) {
      std::istringstream buf(line);
      std::istream_iterator<std::string> begin(buf), end;
      std::vector<std::string> values(begin, end);
      return values[2];
    }
  }

  return "";
}

std::string ProcessParser::getOSName() {
  std::string line;
  std::string name = "PRETTY_NAME";
  std::ifstream stream = Util::getStream((Path::etcPath() + Path::osPath()));

  while (std::getline(stream, line)) {
    if (line.compare(0, name.size(), name) == 0) {
      std::size_t found = line.find("=");
      found++;
      std::string result = line.substr(found);
      result.erase(std::remove(result.begin(), result.end(), '"'),
                   result.end());
      return result;
    }
  }

  return "";
}

int ProcessParser::getTotalThreads() {
  std::string line;
  int result = 0;
  std::string name = "Threads";
  std::vector<std::string> list = ProcessParser::getPidList();

  for (int i = 0; i < list.size(); i++) {
    std::string pid = list[i];
    std::ifstream stream =
        Util::getStream((Path::basePath() + pid + Path::statusPath()));
    while (std::getline(stream, line)) {
      if (line.compare(0, name.size(), name) == 0) {
        std::istringstream buf(line);
        std::istream_iterator<std::string> begin(buf), end;
        std::vector<std::string> values(begin, end);

        result += stoi(values[1]);
        break;
      }
    }
  }

  return result;
}

int ProcessParser::getTotalNumberOfProcesses() {
  std::string line;
  int result = 0;
  std::string name = "processes";

  std::ifstream stream = Util::getStream((Path::basePath() + Path::statPath()));
  while (std::getline(stream, line)) {
    if (line.compare(0, name.size(), name) == 0) {
      std::istringstream buf(line);
      std::istream_iterator<std::string> begin(buf), end;
      std::vector<std::string> values(begin, end);

      result += stoi(values[1]);
      break;
    }
  }

  return result;
}

int ProcessParser::getNumberOfRunningProcesses() {
  std::string line;
  int result = 0;
  std::string name = "procs_running";

  std::ifstream stream = Util::getStream((Path::basePath() + Path::statPath()));
  while (std::getline(stream, line)) {
    if (line.compare(0, name.size(), name) == 0) {
      std::istringstream buf(line);
      std::istream_iterator<std::string> begin(buf), end;
      std::vector<std::string> values(begin, end);

      result += stoi(values[1]);
      break;
    }
  }

  return result;
}

#endif