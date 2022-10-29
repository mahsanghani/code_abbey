//
// Created by Ahsan Ghani on 2022-10-29.
//
#ifndef PATH_H
#define PATH_H

#include <string>
using namespace std;

enum CPUStates {
  S_USER = 1, // Important note:
              // Since the first element is assigned 1,
              // the following ones will auto increment from 2 to n ...
  S_NICE,
  S_SYSTEM,
  S_IDLE,
  S_IOWAIT,
  S_IRQ,
  S_SOFTIRQ,
  S_STEAL,
  S_GUEST,
  S_GUEST_NICE
};

class Path {

public:
  static string basePath() { // In terminal, try "cd /proc/",
                             // and try "cat stat",
                             // something interesting happens.
                             // Use "man proc" to check the manual?
    return "/proc/";
  }
  static string etcPath() { // In terminal, try "cd /etc/",
                            // Simular to commands above
    return "/etc/";
  }
  static string cmdPath() { return "/cmdline"; }
  static string statusPath() { return "/status"; }
  static string statPath() { return "stat"; }
  static string upTimePath() { return "uptime"; }
  static string memInfoPath() { return "meminfo"; }
  static string versionPath() { return "version"; }
  static string cpuInfoPath() { return "cpuinfo"; }
  static string osPath() { return "os-release"; }
};

#endif