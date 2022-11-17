//
// Created by Ahsan Ghani on 2022-11-16.
//
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

void printHello() {
  cout << "Hello from the Worker thread #" << this_thread::get_id();
}