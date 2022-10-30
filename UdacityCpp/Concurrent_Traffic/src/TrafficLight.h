//
// Created by Ahsan Ghani on 2022-10-30.
//

#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include "TrafficObject.h"
#include <condition_variable>
#include <deque>
#include <mutex>

using namespace std;

class Vehicle;

enum class TrafficLightPhase { kRed = 0; kGreen = 1; };

template <class T> class MessageQueue {
public:
  T receive();
  void send(T &&msg);

private:
  mutex mutex_;
  condition_variable cond_;
  deque<T> queue_;
};

class TrafficLight : public TrafficObject {
public:
  TrafficLight();
  TrafficLightPhase getCurrentPhase() const;
  void setCurrentPhase(const TrafficLightPhase color);

  void waitForGreen();
  void simulate() override;

private:
  void cycleThroughPhases();

  shared_ptr<MessageQueue<TrafficLightPhase>> msg_queue_;
  TrafficLightPhase current_phase_;
  condition_variable condition_;
  mutex mutex_;
};

#endif