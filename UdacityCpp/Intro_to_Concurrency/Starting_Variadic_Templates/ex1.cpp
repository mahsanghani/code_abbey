//
// Created by Ahsan Ghani on 2022-11-16.
//
#include <iostream>
#include <string>
#include <thread>

using namespace std;

void printID(int id) {
  this_thread::sleep_for(chrono::milliseconds(50));
  cout << "ID = " << id << endl;
}

void printIDAndName(int id, string name) {
  this_thread::sleep_for(chrono::milliseconds(100));
  cout << "ID = " << id << ", name = " << name << endl;
}