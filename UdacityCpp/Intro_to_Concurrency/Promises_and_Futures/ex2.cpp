//
// Created by Ahsan Ghani on 2022-11-16.
//
#include <future>
#include <iostream>
#include <thread>

using namespace std;

void modifyMessage(promise<string> &&promises, string message) {
  this_thread::sleep_for(chrono::milliseconds(4000)); // simulate work
  string modifiedMessage = message + " has been modified";
  promises.set_value(modifiedMessage);
}