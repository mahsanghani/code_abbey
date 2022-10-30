//
// Created by Ahsan Ghani on 2022-10-30.
//

#include <future>
#include <iostream>
#include <queue>
#include <random>

#include "TrafficLight.h"

using namespace std;

template <typename T> T MessageQueue<T>::receive() {
  unique_lock<mutex> u_lock(mutex_);
  cond_.wait(u_lock, [this] { return !queue.empty(); });

  T msg = move(queue_.back());
  queue_.pop_back();
  return msg;
}