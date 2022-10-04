//
// Created by Ahsan Ghani on 2022-10-04.
//
#include <iostream>

using namespace std;

int main() {
  int *ptr = nullptr;

  ptr = new (nothrow) int;
  if (!ptr) {
    cout << "failed" << endl;
  } else {
    *ptr = 32;
    cout << ptr << endl;
    cout << *ptr << endl;
  }

  int *arr_ptr = new (nothrow) int[3];

  for (int i = 0; i < 3; i++) {
    arr_ptr[i] = (i * i);
  }

  for (int i = 0; i < 3; i++) {
    cout << &arr_ptr[i] << endl;
    cout << arr_ptr[i] << endl;
  }

  delete ptr;
  delete[] arr_ptr;

  return 0;
}