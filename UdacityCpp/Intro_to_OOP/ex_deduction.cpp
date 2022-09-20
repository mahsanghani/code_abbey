//
// Created by Ahsan Ghani on 2022-09-20.
//
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template <typename _Tf> bool func(_Tf x, _Tf y) { return (x < y); }

template <typename _Tf> void print(vector<_Tf> v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << endl;
  }
}
