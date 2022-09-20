//
// Created by Ahsan Ghani on 2022-09-19.
//
#include <iostream>
#include <vector>

using namespace std;

template <typename _Tc> class Container {
private:
  vector<_Tc> arr_;
  int s_;

public:
  Container() : s_(0) { arr_.clear(); }
  int size() const { return Container::s_; }
  void add(_Tc el) {
    Container::s_++;
    arr_.push_back(el);
  }
  void print() const {
    for (_Tc i : arr_) {
      cout << i << " ";
    }
    cout << endl << "Container:: size: " << Container::s_ << endl;
  }
};