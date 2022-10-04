//
// Created by Ahsan Ghani on 2022-10-04.
//
#include <iostream>

using namespace std;

int main() {
  int *int_arr_ptr = new int[5];

  for (int i = 0; i < 5; i++) {
    cout << "int" << endl;
    int input_val;
    cin >> input_val;
    int_arr_ptr[i] = input_val;
  }

  for (int i = 0; i < 5; i++) {
    cout << "number " << int_arr_ptr[i] << "stored " << (int_arr_ptr + i)
         << " address." << endl;
  }

  delete[] int_arr_ptr;
  return 0;
}