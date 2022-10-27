//
// Created by Ahsan Ghani on 2022-10-26.
//
#include "LeakTester.h"
#include "gc_pointer.h"

int main() {
  Pointer<int> p = new int(19);
  p = new int(21);
  p = new int(28);

  return 0;
}