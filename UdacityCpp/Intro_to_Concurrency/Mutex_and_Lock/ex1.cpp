//
// Created by Ahsan Ghani on 2022-11-15.
//
#include <algorithm>
#include <future>
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

double result;

void printResult(int denom) {
  std::cout << "for denom = " << denom << ", the result is " << result
            << std::endl;
}