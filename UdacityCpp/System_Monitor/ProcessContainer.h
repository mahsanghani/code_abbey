//
// Created by Ahsan Ghani on 2022-10-29.
//
#ifndef PROCESs_CONTAINER_H
#define PROCESS_CONTAINER_H

#include "Process.h"
#include <string>
#include <vector>

class ProcessContainer {
public:
  ProcessContainer() { this->refreshList(); }
  void refreshList();
  std::string printList();
  std::vector<std::vector<std::string>> getList();

private:
  std::vector<Process> _list;
};

void ProcessContainer::refreshList() {
  std::vector<std::string> pid_list = ProcessParser::getPidList();
  this->_list.clear();
  for (int i = 0; i < pid_list.size(); i++) {
    Process proc(pid_list[i]);
    this->_list.push_back(proc);
  }
}

std::string ProcessContainer::printList() {
  std::string result = "";
  for (int i = 0; i < this->_list.size(); i++) {
    result += this->_list[i].getProcess();
  }
  return result;
}

std::vector<std::vector<std::string>> ProcessContainer::getList() {
  std::vector<std::vector<std::string>> values;
  std::vector<std::string> stringifiedList;

  for (int i = 0; i < ProcessContainer::_list.size(); i++) {
    stringifiedList.push_back(ProcessContainer::_list[i].getProcess());
  }
  int lastIndex = 0;
  for (int i = 0; i < stringifiedList.size(); i++) {
    if (i % 10 == 0 && i > 0) {
      std::vector<std::string> sub(&stringifiedList[i - 10],
                                   &stringifiedList[i]);
      values.push_back(sub);
      lastIndex = i;
    }
    if (i == (ProcessContainer::_list.size() - 1) && (i - lastIndex) < 10) {
      std::vector<std::string> sub(&stringifiedList[lastIndex],
                                   &stringifiedList[i + 1]);
      values.push_back(sub);
    }
  }
  return values;
}

#endif