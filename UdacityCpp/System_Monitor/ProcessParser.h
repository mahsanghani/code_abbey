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

using namespace std;

class ProcessParser {
private:
  ifstream stream;

public:
  static string getCmd(string pid);
  static vector<string> getPidList();
  static string getVmSize(string pid);
  static string getCpuPercent(string pid);
  static long int getSysUpTime();
  static string getProcUpTime(string pid);
  static string getProcUser(string pid);
  static vector<string> getSysCpuPercent(string coreNumber = "");
  static float getSysRamPercent();
  static string getSysKernelVersion();
  static int getNumberOfCores();
  static int getTotalThreads();
  static int getTotalNumberOfProcesses();
  static int getNumberOfRunningProcesses();
  static string getOSName();
  static string PrintCpuStats(vector<string> values1, vector<string> values2);
  static bool isPidExisting(string pid);
  static float getSysActiveCpuTime(vector<string> values);
  static float getSysIdleCpuTime(vector<string> values);
  static float generateMemory(string line);
};

string ProcessParser::getVmSize(string pid) {

  string line;

  string name = "VmData";
  string value;
  float result;

  ifstream stream =
      Util::getStream((Path::basePath() + pid + Path::statusPath()));

  while (getline(stream, line)) {
    if (line.compare(0, name.size(), name) == 0) {
      istringstream buf(line);
      istream_iterator<string> begin(buf), end;
      vector<string> values(begin, end);

      result = (stof(values[1]) / float(1024 * 1024));
      break;
    }
  }

  return to_string(result);
}

string ProcessParser::getCpuPercent(string pid) {

  string line;

  ifstream stream =
      Util::getStream((Path::basePath() + pid + "/" + Path::statPath()));

  getline(stream, line);
  istringstream buf(line);
  istream_iterator<string> begin(buf), end;
  vector<string> values(begin, end);

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

  return to_string(result);
}

string ProcessParser::getProcUpTime(string pid) {
  string line;
  string value;

  ifstream stream =
      Util::getStream((Path::basePath() + pid + "/" + Path::statPath()));

  getline(stream, line);
  istringstream buf(line);
  istream_iterator<string> begin(buf), end;
  vector<string> values(begin, end);

  return to_string(float(stof(values[13]) / sysconf(_SC_CLK_TCK)));
}

long int ProcessParser::getSysUpTime() {
  string line;
  string value;

  ifstream stream = Util::getStream((Path::basePath() + Path::upTimePath()));

  getline(stream, line);
  istringstream buf(line);
  istream_iterator<string> begin(buf), end;
  vector<string> values(begin, end);

  return stoi(values[0]);
}

string ProcessParser::getProcUser(string pid) {
  string line;

  string name = "Uid";
  string result = "";
  ifstream stream =
      Util::getStream((Path::basePath() + pid + Path::statusPath()));

  while (getline(stream, line)) {
    if (line.compare(0, name.size(), name) == 0) {
      istringstream buf(line);
      istream_iterator<string> begin(buf), end;
      vector<string> values(begin, end);
      result = values[1];
      break;
    }
  }
  stream = Util::getStream("/etc/passwd");
  name = "x:" + result;

  while (getline(stream, line)) {
    if (line.find(name) != string::npos) {
      result = line.substr(0, line.find(":"));
      return result;
    }
  }

  return "";
}

vector<string> ProcessParser::getPidList() {

  DIR *dir;

  vector<string> container;

  if (!(dir = opendir("/proc"))) {
    throw runtime_error(strerror(errno));
  }

  while (dirent *dirp = readdir(dir)) {
    if (dirp->d_type != DT_DIR)
      continue;

    if (all_of(dirp->d_name, dirp->d_name + strlen(dirp->d_name),
               [](char c) { return isdigit(c); })) {
      container.push_back(dirp->d_name);
    }
  }

  if (closedir(dir)) {
    throw runtime_error(strerror(errno));
  }

  return container;
}

string ProcessParser::getCmd(string pid) {
  string line;
  ifstream stream = Util::getStream((Path::basePath() + pid + Path::cmdPath()));
  getline(stream, line);

  return line;
}

int ProcessParser::getNumberOfCores() {
  string line;
  string name = "cpu cores";
  ifstream stream = Util::getStream(Path::basePath() + Path::cpuInfoPath());

  while (getline(stream, line)) {
    if (line.compare(0, name.size(), name) == 0) {
      istringstream buf(line);
      istream_iterator<string> begin(buf), end;
      vector<string> values(begin, end);

      return stoi(values[3]);
    }
  }
}

vector<string> ProcessParser::getSysCpuPercent(string core_number) {
  string line;
  string name = "cpu" + core_number;
  ifstream stream = Util::getStream(Path::basePath() + Path::statPath());

  while (getline(stream, line)) {
    if (line.compare(0, name.size(), name) == 0) {
      istringstream buf(line);
      istream_iterator<string> begin(buf), end;
      vector<string> values(begin, end);

      return values;
    }
  }

  return vector<string>();
}

string ProcessParser::PrintCpuStats(vector<string> values_1,
                                    vector<string> values_2) {
  float active_time = ProcessParser::getSysActiveCpuTime(values_2) -
                      ProcessParser::getSysActiveCpuTime(values_1);
  float idle_time = ProcessParser::getSysIdleCpuTime(values_2) -
                    ProcessParser::getSysIdleCpuTime(values_1);

  float total_time = active_time + idle_time;
  float result = 100.0 * (active_time / total_time);
  return to_string(result);
}

bool ProcessParser::isPidExisting(string pid) {
  vector<string> pid_list = ProcessParser::getPidList();
  if (find(pid_list.begin(), pid_list.end(), pid) != pid_list.end())
    return true;
  else
    return false;
}

float ProcessParser::getSysActiveCpuTime(vector<string> values) {
  return (stof(values[S_USER]) + stof(values[S_NICE]) + stof(values[S_SYSTEM]) +
          stof(values[S_IRQ]) + stof(values[S_SOFTIRQ]) +
          stof(values[S_STEAL]) + stof(values[S_GUEST]) +
          stof(values[S_GUEST_NICE]));
}

float ProcessParser::getSysIdleCpuTime(vector<string> values) {
  return (stof(values[S_IDLE]) + stof(values[S_IOWAIT]));
}

float ProcessParser::getSysRamPercent() {
  string line;
  string name_1 = "MemAvailable:";
  string name_2 = "MemFree:";
  string name_3 = "Buffers:";

  string value;
  int result;
  ifstream stream = Util::getStream((Path::basePath() + Path::memInfoPath()));
  float total_mem = 0;
  float free_mem = 0;
  float buffers = 0;

  while (getline(stream, line)) {
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

float ProcessParser::generateMemory(string line) {
  istringstream buf(line);
  istream_iterator<string> begin(buf), end;
  vector<string> values(begin, end);

  return stof(values[1]);
}

string ProcessParser::getSysKernelVersion() {
  string line;
  string name = "Linux version";
  ifstream stream = Util::getStream((Path::basePath() + Path::versionPath()));

  while (getline(stream, line)) {
    if (line.compare(0, name.size(), name) == 0) {
      istringstream buf(line);
      istream_iterator<string> begin(buf), end;
      vector<string> values(begin, end);
      return values[2];
    }
  }

  return "";
}

string ProcessParser::getOSName() {
  string line;
  string name = "PRETTY_NAME";
  ifstream stream = Util::getStream((Path::etcPath() + Path::osPath()));

  while (getline(stream, line)) {
    if (line.compare(0, name.size(), name) == 0) {
      size_t found = line.find("=");
      found++;
      string result = line.substr(found);
      result.erase(remove(result.begin(), result.end(), '"'), result.end());
      return result;
    }
  }

  return "";
}

int ProcessParser::getTotalThreads() {
  string line;
  int result = 0;
  string name = "Threads";
  vector<string> list = ProcessParser::getPidList();

  for (int i = 0; i < list.size(); i++) {
    string pid = list[i];
    ifstream stream =
        Util::getStream((Path::basePath() + pid + Path::statusPath()));
    while (getline(stream, line)) {
      if (line.compare(0, name.size(), name) == 0) {
        istringstream buf(line);
        istream_iterator<string> begin(buf), end;
        vector<string> values(begin, end);

        result += stoi(values[1]);
        break;
      }
    }
  }

  return result;
}

int ProcessParser::getTotalNumberOfProcesses() {
  string line;
  int result = 0;
  string name = "processes";

  ifstream stream = Util::getStream((Path::basePath() + Path::statPath()));
  while (getline(stream, line)) {
    if (line.compare(0, name.size(), name) == 0) {
      istringstream buf(line);
      istream_iterator<string> begin(buf), end;
      vector<string> values(begin, end);

      result += stoi(values[1]);
      break;
    }
  }

  return result;
}

int ProcessParser::getNumberOfRunningProcesses() {
  string line;
  int result = 0;
  string name = "procs_running";

  ifstream stream = Util::getStream((Path::basePath() + Path::statPath()));
  while (getline(stream, line)) {
    if (line.compare(0, name.size(), name) == 0) {
      istringstream buf(line);
      istream_iterator<string> begin(buf), end;
      vector<string> values(begin, end);

      result += stoi(values[1]);
      break;
    }
  }

  return result;
}

#endif