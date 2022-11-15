//
// Created by Ahsan Ghani on 2022-11-15.
//
#include <algorithm>
#include <future>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;

mutex mtx;
double result;

void printResult(int denom) {
  cout << "for denom = " << denom << ", the result is " << result << endl;
}