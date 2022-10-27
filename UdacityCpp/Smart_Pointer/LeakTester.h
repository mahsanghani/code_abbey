//
// Created by Ahsan Ghani on 2022-10-26.
//

#ifndef LEAKAGE_TEST_H
#define LEAKAGE_TEST_H

#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <exception>
#include <new>

#define INCLUDE_NOTIFICATIONS __Tester__::notifications = true

#define FILE_OUTPUT(name) __Tester__::redirect_output(#name)
#define SCREEN_OUTPUT __Tester__::redirect_output(0)

namespace __Tester__ {
typedef unsigned long ULong;
struct Info {
  void *address;
  long line;
  std::size_t _size;
  bool isArray;
  Info *link;
} * alloc_map(0);
int alloc_count(0), dealloc_count(0);
long alloc_total(0), dealloc_total(0), alloc_current(0), alloc_max(0);
bool notifications(false);
char previous_name[1000] = "";
FILE *output(stdout);

void redirect_output(const char name[]) {
  if (output != stdout)
    fclose(output);
  if (name) {
    if (strcmp(name, previous_name))
      output = fopen(name, "w");
    else
      output = fopen(name, "a");
    if (output) {
      strcpy(previous_name, name);
      return;
    }
  }
  output = stdout;
}

void *Alloc(long line, std::size_t _size, bool isArray) {
  void *address(std::malloc(_size));
  if (!address)
    throw std::bad_alloc();
  if (line != -1) {
    alloc_count++;
    alloc_total += _size;
    alloc_current += _size;
    if (alloc_current > alloc_max)
      alloc_max = alloc_current;
    if (notifications) {
      if (line == -2)
        std::fprintf(output, ">>> Internally allocated ");
      else
        std::fprintf(output,
                     ">>> in %ld. line of the script we have allocated memory "
                     "with the line: ",
                     line);
      std::fprintf(output, "%lu bytes, on address %p\n", (ULong)_size, address);
    }
  }
  Info info = {address, line, _size, isArray, alloc_map};
  if (!(alloc_map = (Info *)std::malloc(sizeof(Info))))
    throw std::bad_alloc();
  *alloc_map = info;
  return address;
}
} // namespace __Tester__