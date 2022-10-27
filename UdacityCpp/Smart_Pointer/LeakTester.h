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
