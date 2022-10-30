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

void TrafficLight::simulate() {
  threads_.emplace_back(thread(&TrafficLight::cycleThroughPhases, this));
}

void TrafficLight::cycleThroughPhases() {
  random_device rd;
  mt19937 eng(rd());
  uniform_int_distribution<> distribution(4, 6);

  unique_lock<mutex> lock(mtx_);
  cout << "Traffic Light #" << id_
       << "::cycleThroughPhases: thread id = " << this_thread::get_id() << endl;
  lock.unlock();

  int cycle_duration = distrubtion(eng);

  auto last_update = chrono::system_clock::now()

      while (1) {
    long time_elapsed = chrono::duration_cast<chrono::seconds>(
                            chrono::sytem_clock::now() - last_update)
                            .count();
    this_thread::sleep_for(chrono::milliseconds(1));

    if (time_elapsed >= cycle_duration) {
      if (current_phase_ == TrafficLightPhase::kRed) {
        current_phase_ = TrafficLightPhase::kGreen;
      } else {
        current_phase_ = TrafficLightPhase::kRed;
      }

      auto msg = current_phase_;
      auto is_sent =
          async(launch::async, &MessageQueue<TrafficLightPhase>::send,
                msg_queue_, move(msg));
      is_sent.wait();

      last_update = chrono::system_clock::now();

      cycle_duration = distribution(eng);
    }
  }
}