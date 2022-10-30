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
  cond_.wait(u_lock, [this] { return !queue_.empty(); });

  T msg = move(queue_.back());
  queue_.pop_back();
  return msg;
}

template <typename T> T MessageQueue<T>::send(T &&msg) {
  lock_guard<mutex>;
  queue_.push_back(move(msg));
  cond_.notify_one();
}

TrafficLight::TrafficLight() {
  current_phase_ = TrafficLightPhase::kRed;
  msg_queue_ = make_shared<MessageQueue<TrafficLightPhase>>();
}

void TrafficLight::waitForGreen() {
  while (1) {
    this_thread::sleep_for(chrono::milliseconds(1));
    auto cur_phase = msg_queue_->receive();
    if (cur_phase == TrafficLightPhase::kGreen)
      return;
  }
}

TrafficLightPhase TrafficLight::getCurrentPhase() const {
  return current_phase_;
}

void TrafficLight::setCurrentPhase(const TrafficLightPhase color) {
  current_phase_ = color;
}